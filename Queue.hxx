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
	Stack *front;
	Stack *rear;
public:
	Queue();
	void Enqueue(Stack*);
	void Dequeue();
	Stack* Front();
	bool isEmpty();
};

#endif /* QUEUE_HXX_ */
