#include "stack.hxx"

template <typename T>
Stack<T>::Stack() : head(nullptr) {}

template <typename T>
void Stack<T>::push(T data)
{
    auto new_node = std::make_shared<Node>(data, head);
    head = new_node;
}

template <typename T>
void Stack<T>::pop()
{
    if (head == nullptr)
    {
        throw std::runtime_error("The stack is empty, there is nothing to pop!");
    }
    head = head->next;
}

template <typename T>
T &Stack<T>::peek()
{
    if (head == nullptr)
    {
        throw std::runtime_error("The stack is empty, there is nothing to peek!");
    }
    return head->data;
}

template <typename T>
bool Stack<T>::isEmpty()
{
    return !head;
}

template <typename T>
void Stack<T>::clear()
{
    head = nullptr;
}