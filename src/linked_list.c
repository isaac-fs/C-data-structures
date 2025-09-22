#include <stdlib.h>

#include "linked_list.h"

static void append(linked_list* linked_list, node* node);
static void destroy(linked_list **linked_list);

linked_list *create_linked_list(node **node_ptr) {
  linked_list *linked_list =
      (struct linked_list *)malloc(sizeof(struct linked_list));
  struct node *node = *node_ptr;
  linked_list->head = node;
  linked_list->tail = node;
  linked_list->length = 1;
  linked_list->destroy = destroy;
  linked_list->append = append;
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

static void append(linked_list* linked_list, node* node) {
  linked_list->tail->next = node;
  linked_list->tail = node;
  return;
}
