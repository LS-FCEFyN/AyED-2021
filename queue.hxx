#ifndef QUEUE_HXX
#define QUEUE_HXX

#include <memory>
#include <stdexcept>

template <typename T>
class Queue
{
public:
    Queue();
    void enqueue(T);
    void dequeue();
    T &front();
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
    std::shared_ptr<Node> rear;
};

#include "queue.cxx"
#endif