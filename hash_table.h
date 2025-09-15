#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdbool.h>

typedef struct {
  char* value;
  int key;
} hash_table;

int hash_function(char* value);
bool insert(char* input);
char* extract(int key);

#endif // HASH_TABLE_H
