#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

#include "node.h"

typedef struct linked_list {
  node *head;
  node *tail;
  int length;
  void (*append)(struct linked_list** linked_list, node** node);
  void (*destroy)(struct linked_list** linked_list);
} linked_list;

linked_list *create_linked_list(node** node);

#endif // LINKED_LIST_H
