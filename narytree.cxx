#include "./queue.hxx"
#include "./narytree.hxx"

template <typename T> nary_tree_node<T>::nary_tree_node(T data) {
  sibling = child = nullptr;
  this->data = data;
}

template <typename T> nary_tree<T>::nary_tree(T data) {
    q = new Queue<nary_tree_node<T>*>();
    parent = new nary_tree_node<T>(data);
    q->Enqueue(parent);
}

template <typename T> void nary_tree<T>::addChild(T data) {
        parent->child = new nary_tree_node<T>(data);
        parent = parent->child;
        q->Enqueue(parent);
}

template <typename T> void nary_tree<T>::addSibling(T data) {

}

template <typename T> void nary_tree<T>::traverseTree() {
    while(! q->isEmpty() ) {
        std::cout << " " << q->Front()->data;
        q->Dequeue();
    }
}
