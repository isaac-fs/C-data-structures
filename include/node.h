#ifndef NODE_H 
#define NODE_H

typedef struct node {
  char* value;
  struct node* next;
  void (*destroy)(struct node** node);
} node;

node* create_node(char* value);

#endif // NODE_H
