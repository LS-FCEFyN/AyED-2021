#include "./narytree.hxx"
template <typename T> explicit nary_tree_node<T>::nary_tree_node(T data) {
  sibling = child = nullptr;
  nivel = 0;
  this->data = data;
}

template <typename T> explicit nary_tree<T>::nary_tree(int N) {
    parent = nullptr;
    q = new Queue<nary_tree_node<T>*>();
    q1 = new Queue<nary_tree_node<T>*>();
    n = N;
}


template <typename T> explicit nary_tree<T>::nary_tree(const nary_tree& ntree) {
    parent = ntree.parent;
    q = malloc(sizeof(ntree.q));
    q = ntree.q;
    q1 = malloc(sizeof(ntree.q1));
    q1 = ntree.q1
    n = ntree.n;
}

T&& nary_tree<T>::operator=() noexcept {
    q = ntree.q;
    q1 = ntree.q1
    n = ntree.n;
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
