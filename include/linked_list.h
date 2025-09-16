#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

#include "node.h"

typedef struct linked_list {
  node* head;
  node* tail;
  int length;
  void (*destroy)(struct linked_list* linked_list);
  void (*append)(struct linked_list* linked_list, node* node);
} linked_list;

linked_list* create_linked_list(node* node);

#endif // LINKED_LIST_H
