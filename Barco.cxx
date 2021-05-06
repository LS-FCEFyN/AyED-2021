/*
 * Barco.cxx
 *
 *  Created on: Apr 30, 2021
 *      Author: Loretta
 */

#include "./barco.hxx"

Barco::Barco(std::string tipo, int posicion[4])
{
    this->setTipo(tipo);
    this->setPosicion(posicion);
}

void Barco::setPosicion(int posicion[4])
{
    for (int i = 0; i < 4; i++) {
        this->posicion[i] = posicion[i];
    }
}

void Barco::setTipo(std::string tipo)
{
    this->tipo = tipo;
}

std::string Barco::getTipo()
{
    return this->tipo;
}

int* Barco::getPosicion()
{
    return this->posicion;
}
