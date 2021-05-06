/*
 * Stack.hxx
 *
 *  Created on: Apr 30, 2021
 *      Author: Loretta
 */

#ifndef STACK_HXX_
#define STACK_HXX_

class Stack {
private:
	int data[2];
	Stack *prev;
public:
	Stack();
	void Push(int, int, Stack*&);
	void Pop(Stack*&);
	int* Peek();

	Stack* getPrev();
	void setPrev(Stack*&);

	bool isEmpty();
};

#endif /* STACK_HXX_ */
