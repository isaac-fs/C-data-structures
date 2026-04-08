#include <stddef.h>
#include <stdio.h>

#include "hash_table.h"
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned int hash(const char *value, size_t value_len);
ht_key insert(hash_table **hash_table_ptr, char *input);
linked_list *extract(hash_table **hash_table_ptr, ht_key key);
void destroy(hash_table **hash_table_ptr);

hash_table *create_hash_table(void) {
  hash_table *hash_table =
      (struct hash_table *)malloc(sizeof(struct hash_table));
  hash_table->table_size = TABLE_SIZE;
  hash_table->values =
      (linked_list **)malloc(sizeof(linked_list *) * hash_table->table_size);
  for (size_t i = 0; i < hash_table->table_size; i++) {
    hash_table->values[i] = create_linked_list();
  }
  hash_table->insert = insert;
  hash_table->extract = extract;
  hash_table->destroy = destroy;
  return hash_table;
}

static ht_key hash(const char *value, size_t value_len) {
  unsigned int sum = 0;

  for (size_t i = 0; i < value_len; i++) {
    sum += (int)value[i];
  }

  return sum % TABLE_SIZE;
};

ht_key insert(hash_table **hash_table_ptr, char *value) {
  hash_table *hash_table = *hash_table_ptr;
  size_t size = strlen(value);
  ht_key key = hash(value, size);
  // Check if the key already has a value
  if (hash_table->values[key]->head) {
    // Yes? Check if value is the same
    size_t size = sizeof(value);
    if (strncmp(hash_table->values[key]->head->value, value, size)) {
      // Values are different, add a new node for conflict resolution
      hash_table->values[key]->append(&hash_table->values[key], value);
    }
  } else {
    // First value for the key, add a new node
    hash_table->values[key]->append(&hash_table->values[key], value);
  }
  return key;
};

linked_list *extract(hash_table **hash_table_ptr, ht_key key) {
  hash_table *hash_table = *hash_table_ptr;
  return hash_table->values[key];
};

void destroy(hash_table **hash_table_ptr) {
  hash_table *hash_table = *hash_table_ptr;
  for (size_t i = 0; i < hash_table->table_size; i++) {
    if (hash_table->values[i]) {
      hash_table->values[i]->destroy(&hash_table->values[i]);
    }
  }
  free(hash_table->values);
  free(hash_table);
  *hash_table_ptr = NULL;
  return;
}
