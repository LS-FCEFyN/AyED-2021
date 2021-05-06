/*
 * Barco.hxx
 *
 *  Created on: Apr 30, 2021
 *      Author: Loretta
 */

#ifndef BARCO_HXX_
#define BARCO_HXX_

#include <string>

class Barco {
private:
    int posicion[4]; /* Posicion del barco */ /* (X,Y) -> Medio cuantos casilleros a ocupar arriba y abajo*/
    std::string tipo; /* El tipo de barco; ejemplo: "Destructor" "Portaaviones" */
public:
    Barco(std::string, int[4]);
    void setPosicion(int[4]);
    void setTipo(std::string);

    int* getPosicion();
    std::string getTipo();
};

#endif /* BARCO_HXX_ */
