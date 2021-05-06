/*
 * Tablero.hxx
 *
 *  Created on: Apr 30, 2021
 *      Author: Loretta
 */

#ifndef TABLERO_HXX_
#define TABLERO_HXX_

typedef int _Bool;
#define false 0
#define true 1
#define na 2

extern char tablero[10][10];
extern _Bool tablaDeDisparos[10][10];

void CopiarPosicionesATablero(int[4]);
void ImprimirTablero();
void TableroInit();

#endif /* TABLERO_HXX_ */
