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

  struct nary_tree_node *(*bfsSearch)(struct nary_tree *self, void *data);
  struct nary_tree_node *(*findMinimum)(struct nary_tree *self);
  struct nary_tree_node *(*findMaximum)(struct nary_tree *self);

  int (*findNodeHeight)(struct nary_tree *self, struct nary_tree_node *node);
  int (*findNodeDepth)(struct nary_tree *self, struct nary_tree_node *node);

  void (*balanceTree)(struct nary_tree *self);

  void (*print)(struct nary_tree *, struct nary_tree_node *, int);

  void (*clear)(struct nary_tree *);
};

struct nary_tree *initialize_nary_tree(int);

#endif