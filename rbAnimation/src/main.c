#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "red_black.h"
#define SPACE 10

int main() {
  red_black *t = rb_new_red_black();

  FILE *file;
  char line[100];
  Record rec;
  tree_node *node;

  if ((file = fopen("numbers.txt", "r")) == NULL) {
    printf("Error! opening file\n");
    exit(1);
  }

  while ((fgets(line, 100, file)) != NULL) {
    rec.key = strdup(strtok(line, "\n"));
    node = rb_new_tree_node(rec);
    rb_insert(t, node);
  }
  fclose(file);

  // rb_inorder(t, t->root);
  // print2D(t, t->root, SPACE);

  return 0;
}
