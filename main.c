#include "nary-tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s [filename]\n", argv[0]);
    return 1;
  }

  struct nary_tree *tree = initialize_nary_tree(2);

  char *filename = argv[1];
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Could not open file '%s'\n", filename);
    return 1;
  }

  char word[256];
  while (fscanf(file, "%s", word) == 1) {
    tree->insert(tree, strdup(word)); // insert word to the tree
  }

  fclose(file);

  // tree->print(tree, tree->root, 0);
  tree->clear(tree);

  return 0;
}