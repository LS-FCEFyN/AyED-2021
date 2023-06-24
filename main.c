#include "nary-tree.h"
#include <stdlib.h>
#include <stdio.h>


size_t calculate_memory_usage_node(struct nary_tree_node *node) {
  if (node == NULL) {
    return 0;
  }

  size_t memory_usage = sizeof(struct nary_tree_node);

  for (int i = 0; i < node->currentChildrenOnLevel; i++) {
    memory_usage += calculate_memory_usage_node(node->children[i]);
  }

  memory_usage += sizeof(struct nary_tree_node *) * node->currentChildrenOnLevel;
  return memory_usage + sizeof(struct nary_tree);
}



int main(int argc, char *argv[])
{

  struct nary_tree *tree = initialize_nary_tree(2);

  char *data1 = "A";
  char *data2 = "B";
  char *data3 = "C";
  char *data4 = "D";
  char *data5 = "E";
  char *data6 = "F";

  tree->insert(tree, data1);
  tree->insert(tree, data2);
  tree->insert(tree, data3);
  tree->insert(tree, data4);
  tree->insert(tree, data5);

  printf("Memory usage: %zu bytes\n", calculate_memory_usage_node(tree->root));

  tree->clear(tree);
  free(tree);

  return 0;
}