/*
 * Stack.cxx
 *
 *  Created on: Apr 30, 2021
 *      Author: Loretta
 */

#include "./Stack.hxx"

Stack::Stack() {
	data[0] = 0;
	data[1] = 0;
	prev = nullptr;
}

void Stack::Push(int x, int y, Stack *&stack) {
	Stack *temp = new Stack();
	temp->data[0] = x;
	temp->data[1] = y;
	temp->prev = stack;
	stack = temp;
}

void Stack::Pop(Stack *&stack) {
	Stack *temp = new Stack();
	if (isEmpty()) {
		return;
	}
	temp = stack;
	stack = temp->prev;
	delete (temp);
}

int* Stack::Peek() {
	return data;
}

Stack* Stack::getPrev() {
	return prev;
}

void Stack::setPrev(Stack *&stack) {
	prev = stack;
}

bool Stack::isEmpty() {
	return prev == nullptr;
}

