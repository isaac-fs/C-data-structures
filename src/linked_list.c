#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

static void destroy(linked_list **linked_list);
static void append(linked_list **linked_list, node **node);
static void print(linked_list *linked_list);

linked_list *create_linked_list(node **node_ptr) {
  linked_list *linked_list =
      (struct linked_list *)malloc(sizeof(struct linked_list));
  struct node *node = *node_ptr;
  linked_list->head = node;
  linked_list->tail = node;
  linked_list->length = 1;
  linked_list->destroy = destroy;
  linked_list->append = append;
  linked_list->print = print;
  return linked_list;
};

static void destroy(linked_list **linked_list_ptr) {
  struct linked_list *linked_list = *linked_list_ptr;
  // Clear the nodes
  while (linked_list->head) {
    node *new_head = linked_list->head->next;
    linked_list->head->destroy(&linked_list->head);
    linked_list->head = new_head;
  }
  // Crear the linked list
  linked_list->tail = NULL;
  free(linked_list);
  *linked_list_ptr = NULL;
  return;
}

static void append(linked_list **linked_list_ptr, node **node_ptr) {
  struct linked_list *list = *linked_list_ptr;
  struct node *node = *node_ptr;
  list->tail->next = node;
  list->tail = node;
  list->length++;
  return;
}

void print(linked_list *linked_list) {
  node *current_node = linked_list->head;
  for (int i = 0; current_node; i++) {
    printf("List[%d] = %s\n", i, current_node->value);
    current_node = current_node->next;
  }
  return;
}
