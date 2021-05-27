#ifndef NARYTREE_HXX_
#define NARYTREE_HXX_

template <class T> class nary_tree_node {
public:
  T data{};
  nary_tree_node<T> *child;
  nary_tree_node<T> *sibling;
  nary_tree_node(T);
};

template <class T> class nary_tree {
private:
  nary_tree_node<T> *parent;
  Queue<nary_tree_node<T> *> *q;

public:
  nary_tree(T data);
  void addChild(T);
  void addSibling(T);
  void traverseTree();
};

#include "./narytree.cxx"
#endif /* NARYTREE_HXX_ */