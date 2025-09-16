#include <stdio.h>

#include "node.h"
#include "linked_list.h"

int main() {
  node* node = create_node("hello");
  linked_list* linked_list = create_linked_list(node);
  printf("linked list head: %s\n", linked_list->head->value);
  printf("linked list tail: %s\n", linked_list->tail->value);
  linked_list->destroy(linked_list);
  printf("linked list head: %p\n", linked_list->head);
  // printf("linked list tail: %p\n", linked_list->tail);
};
