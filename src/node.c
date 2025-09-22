#include <stdlib.h>
#include <string.h>

#include "node.h"

static void destroy(struct node** node_ptr);

node* create_node(char* value) {
  if(!value) {
    abort();
  }
  node *node = (struct node*) malloc(sizeof(struct node));
  node->value = (char*) malloc(sizeof(value));
  memcpy(node->value, value, (int) sizeof(value));
  node->next = NULL;
  node->destroy = destroy;
  return node;
}

static void destroy(struct node** node_ptr) {
  struct node* node = *node_ptr;
  // Free the value
  free(node->value);
  node->value = NULL;
  // Point next to NULl
  node->next = NULL;
  // Free the node
  free(node);
  node = NULL;
  // Set the pointer to NULL
  *node_ptr = NULL;
}
