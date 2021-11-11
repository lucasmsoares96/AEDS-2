#ifndef __RED_BLACK_H
#define __RED_BLACK_H

typedef struct tree_node tree_node;
typedef struct red_black red_black;
typedef struct Record Record;
enum COR { VERMELHO, PRETO };

typedef enum COR COR;

struct Record {
  char *key;
  char *value;
};

struct tree_node {
  Record data;
  tree_node *direita;
  tree_node *esquerda;
  tree_node *p;
  COR cor;
};

struct red_black {
  tree_node *root;
  tree_node *NIL;
};

tree_node *rb_new_tree_node(Record data);
red_black *rb_new_red_black();
tree_node *rb_search(red_black *t, tree_node *x, tree_node *z);

void rb_left_rotate(red_black *t, tree_node *x);
void rb_right_rotate(red_black *t, tree_node *x);

void rb_insert(red_black *t, tree_node *z);
void rb_insert_fixup(red_black *t, tree_node *z);

void rb_transplant(red_black *t, tree_node *u, tree_node *v);
tree_node *rb_minimum(red_black *t, tree_node *x);
void rb_delete_fixup(red_black *t, tree_node *x);
void rb_delete(red_black *t, tree_node *z);

void rb_inorder(red_black *t, tree_node *n);
void rb_print2DUtil(red_black *tree, tree_node *root, int space, int cont);
void rb_print2D(red_black *tree, tree_node *root, int cont);

#endif
