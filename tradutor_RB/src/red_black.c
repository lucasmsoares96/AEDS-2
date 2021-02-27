#include "red_black.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tree_node *rb_new_tree_node(Record data) {
  tree_node *n = malloc(sizeof(tree_node));
  n->esquerda = NULL;
  n->direita = NULL;
  n->p = NULL;
  n->data = data;
  n->cor = VERMELHO;
  return n;
}

red_black *rb_new_red_black() {
  red_black *t = malloc(sizeof(red_black));
  tree_node *nil_node = malloc(sizeof(tree_node));
  nil_node->esquerda = NULL;
  nil_node->direita = NULL;
  nil_node->p = NULL;
  nil_node->cor = PRETO;
  nil_node->data.key = 0;
  nil_node->data.value = 0;
  t->NIL = nil_node;
  t->root = t->NIL;
  return t;
}

tree_node *rb_search(red_black *T, tree_node *x, tree_node *z) {
  if (x == T->NIL) {
    return x;
  }
  if (strcmp(x->data.key, z->data.key) > 0) {
    return rb_search(T, x->esquerda, z);
  } else if (strcmp(x->data.key, z->data.key) < 0) {
    return rb_search(T, x->direita, z);
  }
  return x;
}

void rb_left_rotate(red_black *t, tree_node *x) {
  tree_node *y = x->direita;
  x->direita = y->esquerda;
  if (y->esquerda != t->NIL) {
    y->esquerda->p = x;
  }
  y->p = x->p;
  if (x->p == t->NIL) {
    t->root = y;
  } else if (x == x->p->esquerda) {
    x->p->esquerda = y;
  } else {
    x->p->direita = y;
  }
  y->esquerda = x;
  x->p = y;
}

void rb_right_rotate(red_black *t, tree_node *x) {
  tree_node *y = x->esquerda;
  x->esquerda = y->direita;
  if (y->direita != t->NIL) {
    y->direita->p = x;
  }
  y->p = x->p;
  if (x->p == t->NIL) {
    t->root = y;
  } else if (x == x->p->direita) {
    x->p->direita = y;
  } else {
    x->p->esquerda = y;
  }
  y->direita = x;
  x->p = y;
}

void rb_insert(red_black *t, tree_node *z) {
  tree_node *y = t->NIL;
  tree_node *temp = t->root;
  while (temp != t->NIL) {
    y = temp;
    if (strcmp(z->data.key, temp->data.key) < 0)
      temp = temp->esquerda;
    else if (strcmp(z->data.key, temp->data.key) > 0)
      temp = temp->direita;
    else if (strcmp(z->data.key, temp->data.key) == 0) {
      // printf("%s\n",z->data.key);
      return;
    }
  }
  z->p = y;
  if (y == t->NIL) {
    t->root = z;
  } else if (strcmp(z->data.key, y->data.key) < 0)
    y->esquerda = z;
  else
    y->direita = z;
  z->direita = t->NIL;
  z->esquerda = t->NIL;
  rb_insert_fixup(t, z);
}

void rb_insert_fixup(red_black *t, tree_node *z) {
  while (z->p->cor == VERMELHO) {
    if (z->p == z->p->p->esquerda) {
      tree_node *y = z->p->p->direita;
      if (y->cor == VERMELHO) {
        z->p->cor = PRETO;
        y->cor = PRETO;
        z->p->p->cor = VERMELHO;
        z = z->p->p;
      } else {
        if (z == z->p->direita) {
          z = z->p;
          rb_left_rotate(t, z);
        }
        z->p->cor = PRETO;
        z->p->p->cor = VERMELHO;
        rb_right_rotate(t, z->p->p);
      }
    } else {
      tree_node *y = z->p->p->esquerda;
      if (y->cor == VERMELHO) {
        z->p->cor = PRETO;
        y->cor = PRETO;
        z->p->p->cor = VERMELHO;
        z = z->p->p;
      } else {
        if (z == z->p->esquerda) {
          z = z->p;
          rb_right_rotate(t, z);
        }
        z->p->cor = PRETO;
        z->p->p->cor = VERMELHO;
        rb_left_rotate(t, z->p->p);
      }
    }
  }
  t->root->cor = PRETO;
  // print2D(t, t->root, 10);
}

void rb_transplant(red_black *t, tree_node *u, tree_node *v) {
  if (u->p == t->NIL)
    t->root = v;
  else if (u == u->p->esquerda)
    u->p->esquerda = v;
  else
    u->p->direita = v;
  v->p = u->p;
}

tree_node *rb_minimum(red_black *t, tree_node *x) {
  while (x->esquerda != t->NIL) x = x->esquerda;
  return x;
}

void rb_delete_fixup(red_black *t, tree_node *x) {
  while (x != t->root && x->cor == PRETO) {
    if (x == x->p->esquerda) {
      tree_node *w = x->p->direita;
      if (w->cor == VERMELHO) {
        w->cor = PRETO;
        x->p->cor = VERMELHO;
        rb_left_rotate(t, x->p);
        w = x->p->direita;
      }
      if (w->esquerda->cor == PRETO && w->direita->cor == PRETO) {
        w->cor = VERMELHO;
        x = x->p;
      } else {
        if (w->direita->cor == PRETO) {
          w->esquerda->cor = PRETO;
          w->cor = VERMELHO;
          rb_right_rotate(t, w);
          w = x->p->direita;
        }
        w->cor = x->p->cor;
        x->p->cor = PRETO;
        w->direita->cor = PRETO;
        rb_left_rotate(t, x->p);
        x = t->root;
      }
    } else {
      tree_node *w = x->p->esquerda;
      if (w->cor == VERMELHO) {
        w->cor = PRETO;
        x->p->cor = VERMELHO;
        rb_right_rotate(t, x->p);
        w = x->p->esquerda;
      }
      if (w->direita->cor == PRETO && w->esquerda->cor == PRETO) {
        w->cor = VERMELHO;
        x = x->p;
      } else {
        if (w->esquerda->cor == PRETO) {
          w->direita->cor = PRETO;
          w->cor = VERMELHO;
          rb_left_rotate(t, w);
          w = x->p->esquerda;
        }
        w->cor = x->p->cor;
        x->p->cor = PRETO;
        w->esquerda->cor = PRETO;
        rb_right_rotate(t, x->p);
        x = t->root;
      }
    }
  }
  x->cor = PRETO;
}

void rb_delete(red_black *t, tree_node *z) {
  tree_node *y = z;
  tree_node *x;
  COR y_orignal_cor = y->cor;
  if (z->esquerda == t->NIL) {
    x = z->direita;
    rb_transplant(t, z, z->direita);
  } else if (z->direita == t->NIL) {
    x = z->esquerda;
    rb_transplant(t, z, z->esquerda);
  } else {
    y = rb_minimum(t, z->direita);
    y_orignal_cor = y->cor;
    x = y->direita;
    if (y->p == z) {
      x->p = z;
    } else {
      rb_transplant(t, y, y->direita);
      y->direita = z->direita;
      y->direita->p = y;
    }
    rb_transplant(t, z, y);
    y->esquerda = z->esquerda;
    y->esquerda->p = y;
    y->cor = z->cor;
  }
  if (y_orignal_cor == PRETO) rb_delete_fixup(t, x);
}

void rb_inorder(red_black *t, tree_node *n) {
  if (n != t->NIL) {
    rb_inorder(t, n->esquerda);
    printf("%s/%s\n", n->data.key, n->data.value);
    rb_inorder(t, n->direita);
  }
}

void rb_print2DUtil(red_black *tree, tree_node *root, int space,
                    int cont) {
  if (root == tree->NIL) return;
  space += cont;
  rb_print2DUtil(tree, root->direita, space, cont);
  printf("\n");
  for (int i = cont; i < space; i++) printf(" ");
  if (root->cor == VERMELHO)
    printf("\033[48;5;9m\033[38;5;231m%s\033[m", root->data.key);
  if (root->cor == PRETO)
    printf("\033[48;5;0m\033[38;5;231m%s\033[m", root->data.key);
  rb_print2DUtil(tree, root->esquerda, space, cont);
}

void print2D(red_black *tree, tree_node *root, int cont) {
  rb_print2DUtil(tree, root, 0, cont);
  printf("\n");
}
