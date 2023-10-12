#ifndef NARYTREE_H
#define NARYTREE_H

struct nary_tree_node {
  void *data;
  struct nary_tree_node **children;
  int currentChildrenOnLevel;
};

struct nary_tree {
  struct nary_tree_node *root;

  int numOfChildrenPerLevel;

  void (*insert)(struct nary_tree *self, void *data);
  void (*remove)(struct nary_tree *self, struct nary_tree_node *node);

  struct nary_tree_node *(*bfSearch)(struct nary_tree *self, void *data);
  struct nary_tree_node *(*dfSearch)(struct nary_tree *self, void* data);

  void (*clear)(struct nary_tree *);
};

struct nary_tree *initialize_nary_tree(int);

#endif