/*
 * Tablero.cxx
 *
 *  Created on: Apr 30, 2021
 *      Author: Loretta
 */
#include "./Tablero.hxx"
#include <iostream>

char tablero[10][10] = { { '~', '~', '~', '~', '~', '~', '~', '~', '~', '~' }, {
		'~', '~', '~', '~', '~', '~', '~', '~', '~', '~' }, { '~', '~', '~',
		'~', '~', '~', '~', '~', '~', '~' }, { '~', '~', '~', '~', '~', '~',
		'~', '~', '~', '~' },
		{ '~', '~', '~', '~', '~', '~', '~', '~', '~', '~' }, { '~', '~', '~',
				'~', '~', '~', '~', '~', '~', '~' }, { '~', '~', '~', '~', '~',
				'~', '~', '~', '~', '~' }, { '~', '~', '~', '~', '~', '~', '~',
				'~', '~', '~' }, { '~', '~', '~', '~', '~', '~', '~', '~', '~',
				'~' }, { '~', '~', '~', '~', '~', '~', '~', '~', '~', '~' } };

_Bool tablaDeDisparos[10][10];

void CopiarPosicionesATablero(int posicion[4]) {
	int x, y = 0;

	x = posicion[0];
	y = posicion[1];

	if (posicion[2] == -1) {
		for (int i = 0; i < posicion[3]; i++) {
			tablero[x][y + i] = 'A';
		}
	} else {
		for (int i = 0; i < posicion[3]; i++) {
			tablero[x + i][y] = 'A';
		}
	}
}

void ImprimirTablero() {
	for (int i = 0; i < 10; i++) {
		std::cout << "		";
		for (int j = 0; j < 10; j++) {
			std::cout << tablero[i][j];
		}
		std::cout << std::endl;
	}
}

void TableroInit() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			tablaDeDisparos[i][j] = na;
		}
	}
}
