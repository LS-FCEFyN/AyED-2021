#include "tree.hxx"

template <typename T, int Arity>
Tree<T,Arity>::Tree() : root(nullptr) {};

template <typename T, int Arity>
void Tree<T, Arity>::insert(T data) {
    auto new_node = std::make_shared<Node>(data, children);
    if (root == nullptr) {
        root->data = data;
    }
}