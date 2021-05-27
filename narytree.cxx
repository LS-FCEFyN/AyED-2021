#include "./narytree.hxx"
#include <iostream>


template <typename T> nary_tree<T>::nary_tree() {
  this->child = nullptr;
  this->sibling = nullptr;
}



template <typename T>
nary_tree<T> *nary_tree<T>::addSibling(nary_tree<T> *parent) {
  if (parent == nullptr) {
    return nullptr;
  } else {
    while (parent->sibling) {
      parent = parent->sibling;
    }
    return (parent->sibling = new nary_tree());
  }
}

template <typename T>
nary_tree<T> *nary_tree<T>::addChild(nary_tree<T> *parent) {
  if (parent == nullptr) {
    return nullptr;
  }
  if (parent->child != nullptr) {
    return addSibling(parent->child);
  } else {
    return (parent->child = new nary_tree());
  }
}

template <typename T> void nary_tree<T>::traverseTree(nary_tree<T> *parent) {
  if (parent == nullptr) {
    return;
  } else {
    while (parent) {
      std::cout << " " << parent->data;
      if (parent->child) {
        traverseTree(parent->child);
      }
      parent = parent->sibling;
    }
  }
}
