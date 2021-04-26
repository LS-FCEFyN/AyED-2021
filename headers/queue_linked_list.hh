/*
 * queue_linked_list.hh
 *
 *  Created on: Apr 25, 2021
 *      Author: Loretta
 */

/* Aqui solo encontraras declaraciones */

#ifndef QUEUE_LINKED_LIST_HH_
#define QUEUE_LINKED_LIST_HH_

/* Incluimos este header para poder utilizar << struct Node >> */
#include "./stack_linked_list.hh"

/* Estructura que representa una Cola de Pilas */
struct Queue {
    struct Node* stack;
    struct Queue* next;
};

/* Funcion utilitaria para agregar un nuevo stack a la cola/queue */
/* recibe como parametro un stack << struct Node * >>			  */
void Enqueue(struct Node**);

/* Funcion utilitaria para remover un stack de la cola/queue    */
/* haciendolo siempre desde la primera entrada hasta la final   */
/* recordar que las colas son FIFO y no LIFO				    */
void Dequeue();

/* Funcion utilitaria para imprimir los elementos de la cola */
/* agregada principalmente para propositos de testeo         */
void Print();

#endif /* QUEUE_LINKED_LIST_HH_ */
