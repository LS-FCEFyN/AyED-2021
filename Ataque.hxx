/*
 * Ataque.hxx
 *
 *  Created on: May 1, 2021
 *      Author: Loretta
 */

#ifndef ATAQUE_HXX_
#define ATAQUE_HXX_

#include "Stack.hxx"
#include "Queue.hxx"

void CargarPrimerDisparo(Stack*&);
void CargarPosibleDisparo(Stack*&);
void CargarDisparoHorizontalDer(Stack*&);
void CargarDisparoHorizontalIzq(Stack*&, int[]);
void CargarDisparoVerticalArr(Stack*&);
void CargarDisparoVerticalAba(Stack*&, int[]);
void ContDisparoVerticalAba(Stack*&);
void ContDisparoHorizontalIzq(Stack*&);
void Disparar(Queue*&, int&);

#endif /* ATAQUE_HXX_ */
