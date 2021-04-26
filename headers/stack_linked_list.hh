/*
 * stack_linked_list.hh
 *
 *  Created on: Apr 25, 2021
 *      Author: Loretta
 */

/* Aqui solo encontraras declaraciones */

#ifndef STACK_LINKED_LIST_HH_
#define STACK_LINKED_LIST_HH_

/* Estructura para representar un stack */
struct Node {
    int data[2]; /* Representacion en par ordenado (X,Y) de donde debemos atacar */
    struct Node* link;
};

/* Funcion utilitaria para agregar un nuevo elemento al tope stack  */
/* recibe como argumentos un par ordenado y un stack a modificar 	*/
void push(int, int, struct Node**);

/* Funcion utilitaria para remover el elemento en el tope del stack */
/* recibe como argumento un stack									*/
void pop(struct Node**);

/* Funcion utilitaria para devolver el elemento en el tope del stack */
/* esta funcion tambien se conoce como << top >>					 */
/* devuelve un puntero del tipo int (retorna la direccion en memoria */
/* de << data >> ); recibe como argumento un stack					 */
int* peek(struct Node**);

/* Funcion utilitaria para comprobar si el stack esta vacio */
/* recibe como argumento un stack 							*/
int isEmpty(struct Node**);

#endif /* STACK_LINKED_LIST_HH_ */
