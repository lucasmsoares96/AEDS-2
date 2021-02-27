# Atividade Avaliativa - Aula 7

Lucas Martins Soares

---

Nesse trabalho foi solicitado que fossem implementadas as estruturas básicas, inicialmente de forma estática, para representar os três tipos de representação de grafos:

1. Lista de Adjacência
1. Matriz de Adjacência
1. Matriz de Incidência 

```C
struct lista_de_adjacencia {
  int vertices;
  int arestas;
  TipoLista *vetor;
};
```
Na lista de adjacência temos um ponteiro para um vetor que será alocado dinamicamente durante a execução do código, 2 dois inteiros que armazenarão a quantidade de vertices e de arestas. Cada posição do vetor representará um vertices e armazenará uma lista simplesmente encadeada com todas as arestas daquele vértice. Esta representação funciona bem para grafos de densidade baixa.

Depois de declarada a estrutura seria preciso alocar um vetor do tipo TipoLista e do tamanho do número de vértices que seria recebido pela estrutura.

Para se inserir um novo vértice seria preciso migrar todo o conteúdo do vetor de origem para um vetor maior, adicionar o vértices na nova posição e em seguida atualizar o ponteiro do grafo. E para adicionar uma nova aresta seria preciso percorrer o vetor até que fosse localizado o vértice de origem e adicionar na lista o vértice de destino. E o processo de remoção seria o equivalente.

```C
struct matriz_de_adjacencia {
  int vertices;
  int arestas;
  TipoItem **matriz;//[vertices][vertices]
};
```
Na matriz de adjacência temos um ponteiro duplo para a estrutura que será armazenada no grafo e dois inteiros que armazenarão a quantidade de vértices e de arestas. As linhas e colunas dessa matriz representarão os vértices e as interseções representarão as arestas.Esta representação funciona bem para grafos de densidade alta.

Depois de declarada a estrutura seria preciso alocar uma matriz do tipo TipoItem em que o tamanho das duas dimensões seriam a quantidade de vértices.

Para se inserir um novo vértice seria preciso migrar todo o conteúdo da matriz de origem para uma matriz maior, adicionar o vértices na nova posição e em seguida atualizar o ponteiro do grafo. E para adicionar uma nova aresta seria preciso localizar a interseção dos vértices de origem e destino e adicionar o TipoItem. O mesmo vale para a remoção.
```C
struct matriz_de_incidencia {
  int vertices;
  int arestas;
  TipoItem **matriz;//[vertices][arestas]
};
```
Assim como na matriz de adjacência, na matriz de incidência temos um ponteiro duplo para a estrutura que será armazenada no grafo e dois inteiros que armazenarão a quantidade de vértices e de arestas. As linhas representarão os vértices mas as colunas representarão as arestas.

Depois de declarada a estrutura seria preciso alocar uma matriz do tipo TipoItem em que o número de linhas seria a quantidade de vértices e o número de colunas.

Para se inserir um novo vértice seria preciso migrar todo o conteúdo da matriz de origem para uma matriz com uma linha a mais, adicionar o vértices na nova posição e em seguida atualizar o ponteiro do grafo. E para adicionar uma nova aresta seria preciso migrar todo o conteúdo da matriz de origem para uma matriz com uma coluna a mais, adicionar a aresta na nova posição e em seguida atualizar o ponteiro do grafo. O mesmo vale para a remoção.


## Referencias
https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html#sec:adjlists