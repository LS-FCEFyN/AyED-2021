#include "queue.hxx"

template <typename T>
Queue<T>::Queue() : head(nullptr), rear(nullptr) {}

template <typename T>
void Queue<T>::enqueue(T data)
{
    auto new_node = std::make_shared<Node>(data);
    if (head == nullptr)
    {
        head = rear = new_node;
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
    }
}

template <typename T>
void Queue<T>::dequeue()
{
    auto tmp = head;
    if (head == nullptr)
    {
        throw std::runtime_error("The queue is empty, there is nothing to dequeue!");
    }
    else if (head == rear)
    {
        head = rear = nullptr;
    }
    else
    {
        head = head->next;
    }
    tmp = nullptr;
}

template <typename T>
T &Queue<T>::front()
{
    if (head == nullptr)
    {
        throw std::runtime_error("The queue is empty, there is nothing at the front!");
    }
    else
    {
        return head->data;
    }
}

template <typename T>
void Queue<T>::clear()
{
    while (head != nullptr)
    {
        dequeue();
    }
}

template <typename T>
bool Queue<T>::isEmpty()
{
    return !head;
}