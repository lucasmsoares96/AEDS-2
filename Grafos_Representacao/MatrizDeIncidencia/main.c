#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MatrizDeIncidencia.h"

int main() {
  FILE *file;
  Graph G = GraphInitialize(10);
  Vertex v1, v2;
  v1 = malloc(sizeof(Vertex));
  v2 = malloc(sizeof(Vertex));
  char line[100];
  char *tok;
  char delimiters[] = ",\n";

  if ((file = fopen("../RandomGraph/modelo.txt", "r")) == NULL) {
    printf("Error! opening file\n");
    exit(1);
  }
  while ((fgets(line, 100, file)) != NULL) {
    tok = strtok(line, delimiters);
    int numero = atoi(tok);
    v1->value = numero;
    while ((tok = strtok(NULL, delimiters)) != NULL) {
      v2->value = atoi(tok);
      GraphInsertEdge(G, v1, v2);
    }
  }

  printf("\n=========================================================\n");
  printf("                         Imprime\n");
  printf("=========================================================\n");
  ImprimeGraph(G);

  printf("\n=========================================================\n");
  printf("                         BFS\n");
  printf("=========================================================\n");
  BFS(G, v1);

  printf("\n=========================================================\n");
  printf("                         DFS\n");
  printf("=========================================================\n");
  DFS(G);

  return 0;
}
