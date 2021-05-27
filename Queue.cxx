/*
 * Queue.cxx
 *
 *  Created on: Apr 30, 2021
 *      Author: Loretta
 */

#include "Queue.hxx"

/* Implementation of QueueNode constructor */
template<typename T> QueueNode<T>::QueueNode(T data)
{
    this->data = data ;
    next = nullptr ;
}

/* Implementation of Queue */
template<typename T> Queue<T>::Queue()
{
    front = nullptr ;
    rear = nullptr ;
}


template<typename T> void Queue<T>::Enqueue(T data)
{
    QueueNode<T>* temp = new QueueNode<T>(data);
    if(isEmpty()) {
        front = rear = temp ;
    }
    else {
        rear->next  = temp ;
        rear  = temp ;
    }
}

template<typename T> void Queue<T>::Dequeue()
{
    QueueNode<T> *temp = front;
	if (front == nullptr) {
		return;
	}
	if (front == rear) {
		front = rear = nullptr;
	} else {
		front = front->next;
	}
	delete (temp);
}

template<typename T> T Queue<T>::Front()
{
    if(isEmpty()) {
        return nullptr ;
    }
    else {
        return front->data;
    }
}

template<typename T> bool Queue<T>::isEmpty()
{
    return front == nullptr ;
}
