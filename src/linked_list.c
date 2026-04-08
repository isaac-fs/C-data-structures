#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "node.h"

static void destroy(linked_list **linked_list);
static void append(linked_list **linked_list, const char *value);
static void print(linked_list *linked_list);

linked_list *create_linked_list() {
  linked_list *linked_list =
      (struct linked_list *)malloc(sizeof(struct linked_list));
  linked_list->head = NULL;
  linked_list->tail = NULL;
  linked_list->length = 0;
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
  // Clear the linked list
  linked_list->tail = NULL;
  free(linked_list);
  *linked_list_ptr = NULL;
  return;
}

static void append(linked_list **linked_list_ptr, const char *value) {
  struct linked_list *list = *linked_list_ptr;
  struct node *node = create_node(value);
  // If this is the first node, add it as head
  // The tail should be the same as the head at this point
  if (!list->head && !list->length) {
    list->head = node;
    list->tail = node;
  } else {
    list->tail->next = node;
    list->tail = node;
  }
  list->length++;
  return;
}

static void print(linked_list *linked_list) {
  node *current_node = linked_list->head;
  for (int i = 0; current_node; i++) {
    printf("\tList[%d] = %s\n", i, current_node->value);
    current_node = current_node->next;
  }
  return;
}
