#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

typedef struct lista_de_adjacencia *Lista_de_adjacencia;
typedef struct matriz_de_adjacencia *Matriz_de_adjacencia;
typedef struct matriz_de_incidencia *Matriz_de_incidencia;


struct lista_de_adjacencia {
  int vertices;
  int arestas;
  TipoLista *lista;
};

struct matriz_de_adjacencia {
  int vertices;
  int arestas;
  TipoItem **matriz;//[vertices][vertices]
};

struct matriz_de_incidencia {
  int vertices;
  int arestas;
  TipoItem **matriz;//[vertices][arestas]
};
