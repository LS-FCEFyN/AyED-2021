/*
 * Ataque.cxx
 *
 *  Created on: May 1, 2021
 *      Author: Loretta
 */

#include "Ataque.hxx"
#include "Tablero.hxx"

#include <cstdlib>
#include <iostream>

void CargarPrimerDisparo(Stack *&stack) {
	int x = rand() % 10;
	int y = rand() % 10;
	while (tablaDeDisparos[x][y] != na) {
		x = rand() % 10;
		y = rand() % 10;
	}
	stack->Push(x, y, stack);
}

void CargarPosibleDisparo(Stack *&stack) {
	int x = stack->Peek()[0];
	int y = stack->Peek()[1];
	if ((x - 1) != -1) {
		stack->Push(x - 1, y, stack);
	}
	if ((x + 1) != 10) {
		stack->Push(x + 1, y, stack);
	}
	if ((y - 1) != -1) {
		stack->Push(x, y - 1, stack);
	}
	if ((y + 1) != 10) {
		stack->Push(x, y + 1, stack);
	}
}

void CargarDisparoHorizontalDer(Stack *&stack) {
	stack->Push(stack->Peek()[0] + 1, stack->Peek()[1], stack);
}
void CargarDisparoHorizontalIzq(Stack *&stack, int primercoincidencia[2]) {
	stack->Push(primercoincidencia[0] - 1, stack->Peek()[1], stack);
}
void CargarDisparoVerticalArr(Stack *&stack) {
	stack->Push(stack->Peek()[0], stack->Peek()[1] + 1, stack);
}
void CargarDisparoVerticalAba(Stack *&stack, int primercoincidencia[2]) {
	stack->Push(stack->Peek()[0], primercoincidencia[1] - 1, stack);
}

void ContDisparoVerticalAba(Stack *&stack) {
	stack->Push(stack->Peek()[0], stack->Peek()[1] - 1, stack);
}

void ContDisparoHorizontalIzq(Stack *&stack) {
	stack->Push(stack->Peek()[0] - 1, stack->Peek()[1], stack);
}

void Disparar(Queue *&queue, int &BarcosHundidos) {
	int AciertoPrevio = 0;
	int PrimerCoincidencia[2];
	Stack *temp = queue->Front();
	char Resp;
	bool ori;
	bool cont_abajo = false;
	bool cont_izquierda = false;
	while (!queue->isEmpty()) {
		std::cout << "Fuego en la posicion x = " << temp->Peek()[0] << " y = "
				<< temp->Peek()[1] << " He acertado? ";
		std::cin >> Resp;
		switch (Resp) {
		case 'a':
			if (AciertoPrevio == 0) {
				tablaDeDisparos[temp->Peek()[0]][temp->Peek()[1]] = false;
				queue->Dequeue();
				temp = queue->Front();
			} else if (AciertoPrevio == 1) {
				tablaDeDisparos[temp->Peek()[0]][temp->Peek()[1]] = false;
				temp->Pop(temp);
			} else if (AciertoPrevio > 1 && ori == true) {
				tablaDeDisparos[temp->Peek()[0]][temp->Peek()[1]] = false;
				CargarDisparoHorizontalIzq(temp, PrimerCoincidencia);
				cont_izquierda = true;
			} else if (AciertoPrevio > 1 && ori == false) {
				tablaDeDisparos[temp->Peek()[0]][temp->Peek()[1]] = false;
				CargarDisparoVerticalAba(temp, PrimerCoincidencia);
				cont_abajo = true;
			}
			break;
		case 'v':
			if (AciertoPrevio == 0) {
				tablaDeDisparos[temp->Peek()[0]][temp->Peek()[1]] = true;
				PrimerCoincidencia[0] = temp->Peek()[0];
				PrimerCoincidencia[1] = temp->Peek()[1];
				CargarPosibleDisparo(temp);
				AciertoPrevio++;
			} else if (PrimerCoincidencia[0]
					== temp->Peek()[0]&& cont_abajo == false) {
				tablaDeDisparos[temp->Peek()[0]][temp->Peek()[1]] = true;
				CargarDisparoVerticalArr(temp);
				ori = false;
				AciertoPrevio++;
			} else if (PrimerCoincidencia[1]
					== temp->Peek()[1]&& cont_izquierda == false) {
				tablaDeDisparos[temp->Peek()[0]][temp->Peek()[1]] = true;
				CargarDisparoHorizontalDer(temp);
				ori = true;
				AciertoPrevio++;
			} else if (AciertoPrevio > 1 && cont_izquierda == true) {
				tablaDeDisparos[temp->Peek()[0]][temp->Peek()[1]] = true;
				ContDisparoHorizontalIzq(temp);
			} else if (AciertoPrevio > 1 && cont_abajo == true) {
				tablaDeDisparos[temp->Peek()[0]][temp->Peek()[1]] = true;
				ContDisparoVerticalAba(temp);
			}
			break;
		case 'h':
			tablaDeDisparos[temp->Peek()[0]][temp->Peek()[1]] = true;
			queue->Dequeue();
			temp = queue->Front();
			AciertoPrevio = 0;
			BarcosHundidos++;
			break;
		default:
			break;
		}
	}
}
