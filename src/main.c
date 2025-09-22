#include <stdio.h>

#include "node.h"
#include "linked_list.h"

void test_node() {
  printf("Testing node implementation:\n");
  node *node = create_node("hello");
  printf("node: %p\n", node);
  printf("node next: %p\n", node->next);
  printf("node value: %s\n", node->value);
  node->destroy(&node);
  printf("node: %p\n", node);
  printf("\n");
}

void test_linked_list() {
  printf("Testing linked list implementation:\n");
  node *node = create_node("hello");
  linked_list *linked_list= create_linked_list(&node);
  printf("linked list head: %s\n", linked_list->head->value);
  printf("linked list tail: %s\n", linked_list->tail->value);
  linked_list->destroy(&linked_list);
  printf("linked list: %p\n", linked_list);
  printf("\n");
}

int main() {
  test_node();
  test_linked_list();
};
