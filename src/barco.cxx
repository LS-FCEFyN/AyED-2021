/*
 * barco.cxx
 *
 *  Created on: Apr 25, 2021
 *      Author: Loretta
 */

/*
 * Aqui encontraras las implementaciones de las declaraciones encontradas en
 * "barco.hxx"
 */

#include<string>
#include "../headers/barco.hxx"

Barco::Barco(std::string tipo, int posicion[4][4]) {
	this->setTipo(tipo);
	this->setPosicion(posicion);
}

void Barco::setPosicion(int posicion[4][4]) {
	// TODO
}

void Barco::setTipo(std::string tipo) {
	this->tipo = tipo;
}

std::string Barco::getTipo() {
	return this->tipo;
}
