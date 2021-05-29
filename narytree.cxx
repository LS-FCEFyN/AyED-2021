#include "./queue.hxx"
#include "./narytree.hxx"
template <typename T> nary_tree_node<T>::nary_tree_node(T data) {
  sibling = child = nullptr;
  this->data = data;
}

template <typename T> nary_tree<T>::nary_tree(int N) {
    q = new Queue<nary_tree_node<T>*>();
    q1 = new Queue<nary_tree_node<T>*>();
    n = N;
}

template <typename T> void nary_tree<T>::addChild(T data) {
        parent->child = new nary_tree_node<T>(data);
        parent = parent->child;
}

template <typename T> void nary_tree<T>::addSibling(T data) {
    parent->sibling = new nary_tree_node<T>(data);
    parent = parent->sibling;
}

template<typename T> void nary_tree<T>::add(T data)
{
    if(parent == nullptr) {
        parent = new nary_tree_node<T>(data);
        q1->Enqueue(parent);
    }
    else if(parent->child == nullptr && nodes == 0) {
        addChild(data);
        nodes++;
        q->Enqueue(parent);
        q1->Enqueue(parent);
    }
    else if(parent->sibling ==  nullptr && nodes < n) {
        addSibling(data);
        nodes++;
        q->Enqueue(parent);
        q1->Enqueue(parent);
        if(nodes == n) {
            nodes = 0;
            parent = q->Front();
            q->Dequeue();
        }
    }
}


template <typename T> void nary_tree<T>::traverseTree() {
    while(!q1->isEmpty()) {
        std::cout << " " << q1->Front()->data;
        q1->Dequeue();
    }
}
