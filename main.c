#include "nary-tree.h"
#include <stdio.h>

int main(void) {
  struct nary_tree *btree = initialize_nary_tree(2);
  btree->insert(btree, "HELLO");
  btree->insert(btree, ",");
  btree->insert(btree, "WORLD!");
  btree->insert(btree, (int *)1);

  fprintf(stdout, "%p\n", btree->bfsSearch(btree, (int *)1));

  return 0;
}