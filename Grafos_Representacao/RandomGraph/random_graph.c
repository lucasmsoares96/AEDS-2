#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100
#define MIN_EDGES 80

int main() {
  srand(time(NULL));
  int qtdArestas;
  int vertice;
  int grafo[MAX_VERTICES][MAX_EDGES];

  for (int i = 0; i < MAX_VERTICES; i++) {
    do {
      qtdArestas = rand() % MAX_EDGES;
    } while (qtdArestas < MIN_EDGES);
    for (int j = 0; j < MAX_EDGES; j++) {
      if (j < qtdArestas) {
        vertice = rand() % MAX_VERTICES;
        grafo[i][j] = vertice;
      } else {
        grafo[i][j] = -1;
      }
    }
  }

  for (int i = 0; i < MAX_VERTICES; i++) {
    printf("%d,", i);
    for (int j = 0; j < MAX_EDGES; j++) {
      if (grafo[i][j] != -1) {
        printf("%d,", grafo[i][j]);
      }
    }
    printf("\n");
  }

  return 0;
}
