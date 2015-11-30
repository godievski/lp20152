/* 
 * File:   Tablero.h
 * Author: Usuario
 *
 * Created on 28 de noviembre de 2015, 10:08 PM
 */

#ifndef TABLERO_H
#define	TABLERO_H

#include "TipoA.h"
#include "TipoB.h"
#include "TipoC.h"
#include "Ficha.h"

#include <iostream>
#include <fstream>
using namespace std;

class Tablero {
public:
    Tablero();
    void leerFichas(ifstream&);
    void leerMovimientos(ifstream&);
    void impTablero(void);
private:
    Ficha *fichas[500];
    int cant;
    Ficha* buscarFicha(char*);
};

#endif	/* TABLERO_H */

