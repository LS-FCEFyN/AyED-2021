#ifndef STACK_HXX
#define STACK_HXX

#include <memory>
#include <stdexcept>

template <typename T>
class Stack
{
public:
    Stack();
    void push(T);
    void pop();
    T &peek();
    void clear();
    bool isEmpty();

private:
    struct Node
    {
        T data;
        std::shared_ptr<Node> next;
        Node(T data, std::shared_ptr<Node> next = nullptr) : data(data), next(next) {}
    };
    std::shared_ptr<Node> head;
};

#include "stack.cxx"
#endif