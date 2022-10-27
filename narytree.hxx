#ifndef NARYTREE_HXX_
#define NARYTREE_HXX_

template < class T > class nary_tree_node
{
public:
  T data
  {
  };
  int nivel;
  nary_tree_node < T > *child;
  nary_tree_node < T > *sibling;
  explicit nary_tree_node (T);
};

template < class T > class nary_tree
{
private:
  int n
  {
  };
  int nodes
  {
  };

  void addChild (T);
  void addSibling (T);

  nary_tree_node < T > *parent;
  Queue < nary_tree_node < T > *>*q;
  Queue < nary_tree_node < T > *>*q1;

public:
  explicit nary_tree (int);
  explicit nary_tree (const nary_tree &);
  T & operator= (T &&) noexcept;
  void traverseTree ();
  void add (T);
};

#include "./narytree.cxx"
#endif /* NARYTREE_HXX_ */
