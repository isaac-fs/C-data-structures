#include <stdio.h>

#include "hash_table.h"
#include "linked_list.h"
#include "node.h"

void test_node() {
  printf("Testing node implementation\n");
  node *node = create_node("hello");
  printf("\tCreated new node with value %s\n", node->value);
  printf("\tNode next: %p\n", node->next);
  printf("\tDestroying node...\n");
  node->destroy(&node);
  printf("\tNode: %p\n", node);
}

void test_linked_list() {
  printf("Testing linked list implementation\n");
  linked_list *linked_list = create_linked_list();
  printf("\tCreated new linked list\n");
  printf("\tLinked list length: %d\n", linked_list->length);
  printf("\tAppeding node to list...\n");
  linked_list->append(&linked_list, "hello");
  printf("\tLinked list head: %s\n", linked_list->head->value);
  printf("\tLinked list tail: %s\n", linked_list->tail->value);
  printf("\tLinked list length: %d\n", linked_list->length);
  printf("\tPrinting linked list...\n");
  linked_list->print(linked_list);
  printf("\tDestroying linked list...\n");
  linked_list->destroy(&linked_list);
  printf("\tLinked list: %p\n", linked_list);
}

void test_hash_table() {
  printf("Testing hast table implementation\n");
  char *str = "hello";
  hash_table *hash_table = create_hash_table();
  printf("\tCreated a new hash table\n");
  printf("\tAdding value %s\n", str);
  ht_key key = hash_table->insert(&hash_table, str);
  printf("\tGot key %u\n", key);
  char *out = hash_table->extract(&hash_table, key);
  printf("\tGot value %s using key %u\n", out, key);
  printf("\tDestroying hash table\n");
  hash_table->destroy(&hash_table);
  printf("\tHash table %p\n", hash_table);
}

int main() {
  printf("\n");
  test_node();
  printf("\n");
  test_linked_list();
  printf("\n");
  test_hash_table();
};
