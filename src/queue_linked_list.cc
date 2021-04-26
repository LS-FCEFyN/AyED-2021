/*
 * queue_linked_list.cc
 *
 *  Created on: Apr 25, 2021
 *      Author: Loretta
 */

/* Aqui encontraras las implementaciones    */
/* para ver las declaraciones por favor vea */
/* 			queue_linked_list.hh			*/

#include <stdlib.h>
#include <stdio.h>
#include "./queue_linked_list.hh"

/* Punteros hacia el frente y la parte posterior de la cola respectivamente */
struct Queue* front = NULL;
struct Queue* rear = NULL;

/* Quiza si agrego estos punteros dentro de la estructura que representa la cola 		*/
/* podria hacer que las funciones Dequeue() y Print() trabajen con multiples colas ?	*/
/* de todas formas esto cae fuera del alcance del proecto								*/

/* Funcion utilitaria para agregar un nuevo stack a la cola/queue */
/* recibe como parametro un stack/pila							  */
void Enqueue(struct Node** stack)
{
    struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue*));
    temp->stack = (*stack);
    temp->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

void Dequeue()
{
    struct Queue* temp = front;

    if (front == NULL) {
        fprintf(stderr, "Underflow\n");
        exit(EXIT_FAILURE);
    }
    if (front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->next;
    }

    free(temp);
}

void Print()
{
    struct Queue* temp = front;
    while (temp != NULL) {
        fprintf(stdout, "Address: %p\n", (void*)temp->stack);
        temp = temp->next;
    }
    fprintf(stdout, "\n");
}
