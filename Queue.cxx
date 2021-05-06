/*
 * Queue.cxx
 *
 *  Created on: Apr 30, 2021
 *      Author: Loretta
 */

#include "./Queue.hxx"

Queue::Queue() {
	front = nullptr;
	rear = nullptr;
}

void Queue::Enqueue(Stack *stack) {
	Stack *temp = new Stack();
	temp->Push(stack->Peek()[0], stack->Peek()[1], temp);
	if (isEmpty()) {
		front = rear = temp;
		return;
	}
	rear->setPrev(temp);
	rear = temp;
}

void Queue::Dequeue() {
	Stack *temp = front;
	if (front == nullptr) {
		return;
	}
	if (front == rear) {
		front = rear = nullptr;
	} else {
		front = front->getPrev();
	}
	delete (temp);
}

Stack* Queue::Front() {
	return front;
}

bool Queue::isEmpty() {
	return front == nullptr && rear == nullptr;
}
