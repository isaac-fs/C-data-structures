#include <stdio.h>

#include "linked_list.h"
#include "node.h"

void test_node() {
  printf("Testing node implementation:\n");
  node *node = create_node("hello");
  printf("Created new node with value %s\n", node->value);
  printf("Node next: %p\n", node->next);
  printf("Destroying node...\n");
  node->destroy(&node);
  printf("Node: %p\n", node);
  printf("\n");
}

void test_linked_list() {
  printf("Testing linked list implementation:\n");
  node *node = create_node("hello");
  linked_list *linked_list = create_linked_list(&node);
  printf("Created new linked list\n");
  printf("Linked list head: %s\n", linked_list->head->value);
  printf("Linked list tail: %s\n", linked_list->tail->value);
  printf("Linked list length: %d\n", linked_list->length);
  printf("Appeding node to list...\n");
  struct node *node2 = create_node("world");
  linked_list->append(&linked_list, &node2);
  printf("Linked list head: %s\n", linked_list->head->value);
  printf("Linked list tail: %s\n", linked_list->tail->value);
  printf("Linked list length: %d\n", linked_list->length);
  printf("Destroying linked list...\n");
  linked_list->destroy(&linked_list);
  printf("linked list: %p\n", linked_list);
  printf("\n");
}

int main() {
  test_node();
  test_linked_list();
};
