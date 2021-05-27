#ifndef NARYTREE_HXX_
#define NARYTREE_HXX_

template <class T> class nary_tree {
private:
  T data{};
  nary_tree<T> *child;
  nary_tree<T> *sibling;

public:
  nary_tree();
  nary_tree<T> *addChild(nary_tree<T> *);
  nary_tree<T> *addSibling(nary_tree<T> *);
  void traverseTree(nary_tree<T> *);
};

#include "./narytree.cxx"
#endif /* NARYTREE_HXX_ */
