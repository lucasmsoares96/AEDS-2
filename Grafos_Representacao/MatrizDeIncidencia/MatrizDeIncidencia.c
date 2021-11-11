#include "MatrizDeIncidencia.h"

#include <stdio.h>
#include <stdlib.h>

//// procs FILA
Fila *FFVazia() {
  Fila *f = (Fila *)malloc(sizeof(Fila));
  f->head = NULL;
  f->tail = NULL;
  f->size = 0;
  return f;
}
void Queue(Fila *f, int vertex) {
  Item *d = (Item *)malloc(sizeof(Item));
  d->data = vertex;
  d->prox = NULL;
  if (f->head == NULL) {
    f->head = d;
    f->tail = d;
  } else {
    f->tail->prox = d;
    f->tail = d;
  }
  f->size++;
}
Item *Dequeue(Fila *f) {
  Item *aux;
  if (f->head == NULL) return NULL;
  aux = f->head;
  f->head = f->head->prox;
  f->size--;
  return aux;
}
//// fim procs FILA

Vertex VertexInitialize(int value) {
  Vertex v = malloc(sizeof(Vertex));
  v->value = value;
  return v;
}

Graph GraphInitialize(int V) {
  Graph G = malloc(sizeof(Graph));
  G->V = V;
  G->E = 0;
  G->matrizDeIncidencia = (Vertex **)malloc(V * sizeof(Vertex *));
  for (int i = 0; i < G->V; i++) {
    G->matrizDeIncidencia[i] = (Vertex *)malloc(G->E * sizeof(Vertex));
    for (int j = 0; j < 1; j++) {
      G->matrizDeIncidencia[i][j] = VertexInitialize(0);
    }
  }
  return G;
}

void GraphInsertEdge(Graph G, Vertex v1, Vertex v2) {
  G->E++;
  for (int i = 0; i < G->V; i++) {
    G->matrizDeIncidencia[i] =
        (Vertex *)realloc(G->matrizDeIncidencia[i], G->E * sizeof(Vertex));
    if (i == v1->value) {
      G->matrizDeIncidencia[i][G->E - 1] = VertexInitialize(1);
    } else if (i == v2->value) {
      G->matrizDeIncidencia[i][G->E - 1] = VertexInitialize(-1);
    } else {
      G->matrizDeIncidencia[i][G->E - 1] = VertexInitialize(0);
    }
  }
}

void ImprimeGraph(Graph G) {
  printf("       ");
  for (int j = 0; j < G->E; j++) {
    printf("[%2d]", j);
  }
  printf("\n");
  printf("       ");
  for (int j = 0; j < G->E; j++) {
    printf(" |  ", j);
  }
  printf("\n");
  printf("       ");
  for (int j = 0; j < G->E; j++) {
    printf(" V  ", j);
  }
  printf("\n");
  for (int i = 0; i < G->V; i++) {
    printf("[%2d]-> ", i);
    for (int j = 0; j < G->E; j++) {
      if (G->matrizDeIncidencia[i][j]->value == 1) {
        printf("[ 1]");
      } else if (G->matrizDeIncidencia[i][j]->value == -1) {
        printf("[-1]");
      } else {
        printf("[  ]");
      }
    }
    printf("\n");
  }
}

void DFS_VISIT(Graph G, Vertex *v, int index, int *cor, int *d, int *f,
               int *tempo) {
  cor[index] = 1;
  *tempo += 1;
  d[index] = *tempo;
  for (int a = 0; a < G->E; a++) {
    if (v[a]->value == 1) {
      for (int u = 0; u < G->V; u++) {
        if (u != index && G->matrizDeIncidencia[u][a]->value == -1 &&
            cor[u] == 0) {
          DFS_VISIT(G, G->matrizDeIncidencia[u], u, cor, d, f, tempo);
        }
      }
    }
  }
  cor[index] = 2;
  *tempo += 1;
  f[index] = *tempo;
  printf("Vertex:%3d  |  D:%3d  |  F:%3d\n", index, d[index], f[index]);
}

void DFS(Graph G) {
  int cor[G->V];  // Branco 0, Cinza 1, Preto 2
  int d[G->V];    // Tempo de descoberta
  int f[G->V];    // Tempo de finalização
  int tempo = 0;
  for (int v = 0; v < G->V; v++) cor[v] = 0;
  for (int v = 0; v < G->V; v++)
    if (cor[v] == 0)
      DFS_VISIT(G, G->matrizDeIncidencia[v], v, cor, d, f, &tempo);
}

void BFS(Graph G, Vertex s) {
  int cor[G->V];  // 0 Branco, 1 Cinza, 2 Preto
  int d[G->V];
  int pi[G->V];  // -1 == NULL
  Fila *f = FFVazia();
  for (int i = 0; i < G->V; i++)
    if (i != s->value) {
      cor[i] = 0;
      d[i] = -1;   // infinito
      pi[i] = -1;  // ? não tem pai ainda
    }
  cor[s->value] = 1;
  d[s->value] = 0;
  pi[s->value] = -1;
  Queue(f, s->value);

  while (f->size > 0) {
    Item *u = Dequeue(f);
    for (int a = 0; a < G->E; a++) {
      if (G->matrizDeIncidencia[u->data][a]->value == 1) {
        for (int v = 0; v < G->V; v++) {
          if (v != u->data && G->matrizDeIncidencia[v][a]->value == -1 &&
              cor[v] == 0) {
            cor[v] = 1;
            d[v] = d[u->data] + 1;
            pi[v] = u->data;
            Queue(f, v);
            break;
          }
        }
      }
    }
    cor[u->data] = 2;
    printf("Vertex:%3d\n", u->data);
  }
}
