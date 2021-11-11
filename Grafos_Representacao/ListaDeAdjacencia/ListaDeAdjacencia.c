#include "ListaDeAdjacencia.h"

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
  v->prox = NULL;
  return v;
}

Graph GraphInitialize(int V) {
  Graph G = malloc(sizeof(Graph));
  G->V = V;
  G->E = 0;
  G->adj = malloc(V * sizeof(Vertex));
  for (int v = 0; v < V; v++) G->adj[v] = VertexInitialize(v);
  return G;
}

void GraphInsertEdge(Graph G, Vertex v1, Vertex v2) {
  Vertex v = G->adj[v1->value];

  while (v->prox != NULL) {
    if (v->value == v2->value) return;
    v = v->prox;
  }

  v->prox = VertexInitialize(v2->value);
  G->E++;
}

void ImprimeGraph(Graph G) {
  Vertex aux;

  for (int v = 0; v < G->V; v++) {
    aux = G->adj[v];
    printf("[%2d]-> ", aux->value);
    aux = aux->prox;
    while (aux != NULL) {
      printf("%2d-> ", aux->value);
      aux = aux->prox;
    }
    printf("\n");
  }
}

void DFS_VISIT(Graph G, Vertex v, int *cor, int *d, int *f, int *tempo) {
  cor[v->value] = 1;
  *tempo += 1;
  d[v->value] = *tempo;

  for (Vertex u = G->adj[v->value]; u != NULL; u = u->prox)
    if (cor[u->value] == 0) DFS_VISIT(G, u, cor, d, f, tempo);

  cor[v->value] = 2;
  *tempo += 1;
  f[v->value] = *tempo;
  printf("Vertex:%3d  |  D:%3d  |  F:%3d\n", v->value, d[v->value],
         f[v->value]);
}

void DFS(Graph G) {
  int cor[G->V];  // Branco 0, Cinza 1, Preto 2
  int d[G->V];    // Tempo de descoberta
  int f[G->V];    // Tempo de finalização
  int tempo = 0;

  for (int v = 0; v < G->V; v++) cor[v] = 0;

  for (int v = 0; v < G->V; v++)
    if (cor[v] == 0) DFS_VISIT(G, G->adj[v], cor, d, f, &tempo);
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
    for (Vertex v = G->adj[u->data]; v != NULL; v = v->prox) {
      if (cor[v->value] == 0) {
        cor[v->value] = 1;
        d[v->value] = d[u->data] + 1;
        pi[v->value] = u->data;
        Queue(f, v->value);
      }
    }

    cor[u->data] = 2;
    printf("Vertex:%3d\n", u->data);
  }
}
