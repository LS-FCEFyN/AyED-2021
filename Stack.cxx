#include "./Stack.hxx"

template<typename T> explicit StackNode<T>::StackNode(T data)
{
    this->data = data;
    next = nullptr;
}


template<typename T> Stack<T>::Stack()
{
    head = nullptr;
}

template<typename T> void Stack<T>::Push(T data)
{
    StackNode<T> *temp = new StackNode<T>(data);
    if(isEmpty()) {
        head = temp;
    }
    temp->next = head;
    head = temp;
}

template<typename T> void Stack<T>::Pop()
{
    StackNode<T> *temp = head;
    if(isEmpty()) {
        return;
    }
    head = temp->next;
    delete(temp);
}

template<typename T> T Stack<T>::Peek()
{
    return head->data;
}


template<typename T> bool Stack<T>::isEmpty()
{
    return head == nullptr;
}
