#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "red_black.h"
#define SPACE 10

int main() {
  red_black *t = rb_new_red_black();

  FILE *file;
  char line[100];
  char phrase[100];
  char *word;
  Record rec;
  tree_node *node;

  if ((file = fopen("ingles.txt", "r")) == NULL) {
    printf("Error! opening file\n");
    exit(1);
  }

  while ((fgets(line, 100, file)) != NULL) {
    rec.key = strdup(strtok(line, "#\n"));
    rec.value = strdup(strtok(NULL, "#\n"));
    node = rb_new_tree_node(rec);
    rb_insert(t, node);
  }
  fclose(file);

  // inorder(t, t->root);
  // print2D(t, t->root, SPACE);

  system("clear");
  printf("Entre com a frase a ser traduzida:\n");
  // char phrase[] = "I love you";
  fgets(phrase, sizeof(phrase), stdin);
  phrase[strcspn(phrase, "\n")] = 0;

  word = strtok(phrase, " ");
  while (word != NULL) {
    rec.key = word;
    node = rb_new_tree_node(rec);
    node = rb_search(t, t->root, node);
    if (node != t->NIL) {
      printf("%s ", node->data.value);
    } else {
      printf("%s ", rec.key);
    }
    word = strtok(NULL, " ");
  }
  printf("\n");

  return 0;
}
