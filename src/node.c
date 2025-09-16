#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"

static void destroy(struct node* node);

node* create_node(char* value) {
  if(!value) {
    abort();
  }
  node* node = (struct node*) malloc(sizeof(struct node));
  node->value = (char*) malloc(sizeof(value));
  memcpy(node->value, value, (int) sizeof(value));
  node->next = NULL;
  node->destroy = destroy;
  return node;
}

static void destroy(struct node* node) {
  free(node->value);
  node->value = NULL;
  free(node);
  node = NULL;
}
