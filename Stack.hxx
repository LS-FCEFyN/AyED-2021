#ifndef STACK_HXX_
#define STACK_HXX_

template <class T>
class StackNode {
public:
    StackNode(T);
    T data{};
    StackNode<T>* next;
};

template <class T>
class Stack {
private:
    StackNode<T>* head;
public:
    Stack();
    void Push(T);
    void Pop();
    T Peek();
    bool isEmpty();
};

#include "./stack.cxx"
#endif /* STACK_HXX_ */
