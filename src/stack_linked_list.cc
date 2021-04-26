/*
 * stack_linked_list.cc
 *
 *  Created on: Apr 25, 2021
 *      Author: Loretta
 */

/* Aqui encontraras las implementaciones    */
/* para ver las declaraciones por favor vea */
/* 			stack_linked_list.hh			*/

#include "../headers/stack_linked_list.hh"
#include <stdlib.h>
#include <stdio.h>

void push(int x, int y, struct Node** stack)
{
    if (stack != NULL) {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data[0] = x;
        temp->data[1] = y;
        temp->link = *stack;
        *stack = temp;
    }
    else {
        /* Todavia estoy tratando de ver que mensaje es mas apropiado */
        /* fprintf(stderr,"\n") */
        exit(EXIT_FAILURE);
    }
}

void pop(struct Node** stack)
{
    struct Node* temp;

    if (stack != NULL) {
        if (*stack != NULL) {
            temp = *stack;
            (*stack) = temp->link;
            free(temp);
        }
        else {
            fprintf(stderr, "Underflow\n");
            exit(EXIT_FAILURE);
        }
    }
}

int* peek(struct Node** stack)
{
    if (!isEmpty(stack)) {
        return (*stack)->data;
    }
    fprintf(stderr, "Error, stack is empty\n");
    exit(EXIT_FAILURE);
}

int isEmpty(struct Node** stack) { return *stack == NULL; }
