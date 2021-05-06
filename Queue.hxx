/*
 * Queue.hxx
 *
 *  Created on: Apr 30, 2021
 *      Author: Loretta
 */

#ifndef QUEUE_HXX_
#define QUEUE_HXX_

#include "./Stack.hxx"

class Queue {
private:
	Stack *stack;
	Queue *front;
	Queue *rear;
public:
	Queue();
	void Enqueue(Stack*);
	void Dequeue();
	Stack* Front();
	bool isEmpty();
};

#endif /* QUEUE_HXX_ */
