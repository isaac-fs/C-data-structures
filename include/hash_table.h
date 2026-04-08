#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "linked_list.h"
#include <stdbool.h>
#include <stdlib.h>

#define TABLE_SIZE 1000

typedef unsigned int ht_key;

typedef struct hash_table {
  linked_list **values;
  ht_key (*insert)(struct hash_table **hash_table, char *value);
  linked_list *(*extract)(struct hash_table **hash_table, ht_key key);
  void (*destroy)(struct hash_table **hash_table_ptr);
  size_t table_size;
} hash_table;

hash_table *create_hash_table(void);

#endif // HASH_TABLE_H
