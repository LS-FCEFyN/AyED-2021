/*
 * barco.hxx
 *
 *  Created on: Apr 25, 2021
 *      Author: Loretta
 */

/*
 * Aqui solo encontraras declaraciones
 */

#ifndef BARCO_HXX_
#define BARCO_HXX_

#include <string>

class Barco{
private:
	int posicion[4][4]; 	/* Posicion del barco */
	std::string tipo;	/* El tipo de barco; ejemplo: "Destructor" "Portaaviones" */
public:
	Barco(std::string, int [4][4]);
	void setPosicion(int [4][4]);
	void setTipo(std::string);

	std::string getTipo(); /* Misc. added only for testing purposes */
};

#endif /* BARCO_HXX_ */
