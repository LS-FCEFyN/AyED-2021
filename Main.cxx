/*
 * Main.cxx
 *
 *  Created on: Apr 30, 2021
 *      Author: Loretta
 */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "./Stack.hxx"
#include "./Queue.hxx"
#include "./Barco.hxx"
#include "./Ataque.hxx"
#include "./Tablero.hxx"

int main(int argc, char **argv) {

	srand(time(0));
	int BarcosHundidos = 0;

	/* REPRESENTACION DEL TABLERO SIN BARCOS */
	/*__A*B*C*D*E*F*G*H*I*J */
	/*0|0 0 0 0 0 0 0 0 0 0 */
	/*1|0 0 0 0 0 0 0 0 0 0 */
	/*2|0 0 0 0 0 0 0 0 0 0 */
	/*3|0 0 0 0 0 0 0 0 0 0 */
	/*4|0 0 0 0 0 0 0 0 0 0 */
	/*5|0 0 0 0 0 0 0 0 0 0 */
	/*6|0 0 0 0 0 0 0 0 0 0 */
	/*7|0 0 0 0 0 0 0 0 0 0 */
	/*8|0 0 0 0 0 0 0 0 0 0 */
	/*9|0 0 0 0 0 0 0 0 0 0 */
	/*--A*B*C*D*E*F*G*H*I*J */

	/* Los primeros dos numeros [0] & [1] indicaran la cabeza de la nave  */
	/* el tercer numero [2], indicara la orientacion de la nave (parada 1 */
	/* o acostada -1) el cuarto numero [3], indicara el largo de la nave  */

	/* Destructor */
	int p_b1[4] = { 0, 1, 1, 4 };

	/* Cruceros */
	int p_b2[4] = { 2, 6, 1, 3 };
	int p_b3[4] = { 6, 3, -1, 3 };

	/* Ca�oneras */
	int p_b4[4] = { 8, 3, -1, 2 };
	int p_b5[4] = { 8, 6, -1, 2 };
	int p_b6[4] = { 8, 9, 1, 2 };

	/* Submarinos */
	int p_b8[4] = { 4, 3, 0, 1 };
	int p_b9[4] = { 5, 8, 0, 1 };
	int p_b7[4] = { 9, 0, 0, 1 };
	int p_b10[4] = { 3, 8, 0, 1 };

	/* REPRESENTACION DEL TABLERO CON BARCOS */
	/*__A*B*C*D*E*F*G*H*I*J */
	/*0|0 1 0 0 0 0 0 0 0 0 *//* Los '1' representan el Desturcor  */
	/*1|0 1 0 0 0 0 0 0 0 0 *//* Los '2' representan el Crucero	*/
	/*2|0 1 0 0 0 0 2 0 0 0 *//* Los '3' representan la Cañoneras  */
	/*3|0 1 0 0 0 0 2 0 4 0 *//* Los '4' representan el Submarinos */
	/*4|0 0 0 4 0 0 2 0 0 0 */
	/*5|0 0 0 0 0 0 0 0 4 0 */
	/*6|0 0 0 2 2 2 0 0 0 0 */
	/*7|0 0 0 0 0 0 0 0 0 0 */
	/*8|0 0 0 3 3 0 3 3 0 3 */
	/*9|4 0 0 0 0 0 0 0 0 3 */
	/*--A*B*C*D*E*F*G*H*I*J */

	Barco destructor = Barco("Destructor", p_b1);
	Barco crucero1 = Barco("Crucero", p_b2);
	Barco crucero2 = Barco("Crucero", p_b3);
	Barco canonera1 = Barco("Cañoneras", p_b4);
	Barco canonera2 = Barco("Cañoneras", p_b5);
	Barco canonera3 = Barco("Cañoneras", p_b6);
	Barco submarino1 = Barco("Submarino", p_b7);
	Barco submarino2 = Barco("Submarino", p_b8);
	Barco submarino3 = Barco("Submarino", p_b9);
	Barco submarino4 = Barco("Submarino", p_b10);

	CopiarPosicionesATablero(destructor.getPosicion());
	CopiarPosicionesATablero(crucero1.getPosicion());
	CopiarPosicionesATablero(crucero2.getPosicion());
	CopiarPosicionesATablero(canonera1.getPosicion());
	CopiarPosicionesATablero(canonera2.getPosicion());
	CopiarPosicionesATablero(canonera3.getPosicion());
	CopiarPosicionesATablero(submarino1.getPosicion());
	CopiarPosicionesATablero(submarino2.getPosicion());
	CopiarPosicionesATablero(submarino3.getPosicion());
	CopiarPosicionesATablero(submarino4.getPosicion());

	ImprimirTablero();
	TableroInit();

	Stack *stack = new Stack();
	Stack *stack1 = new Stack();
	Queue *queue = new Queue();
	while (BarcosHundidos != 10) {
		CargarPrimerDisparo(stack);
		CargarPrimerDisparo(stack1);
		queue->Enqueue(stack);
		queue->Enqueue(stack1);
		Disparar(queue, BarcosHundidos);
	}

	delete (stack);
	delete (stack1);
	delete (queue);

	return 0;
}
