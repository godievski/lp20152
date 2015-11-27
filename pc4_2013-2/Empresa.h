/* 
 * File:   Empresa.h
 * Author: Usuario
 *
 * Created on 19 de noviembre de 2015, 02:46 PM
 */

#ifndef EMPRESA_H
#define	EMPRESA_H

#include "Omnibus.h"
#include "Pasajero.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

class Empresa {
public:
    Empresa();
    virtual ~Empresa ();
    void leerRutas (ifstream&);
    void leerPasajeros (ifstream &);
    void impReporte (void);
    void setDireccion(char* direccion);
    void setRuc(int ruc);
    void setNombre(char* nombre);
private:
    char *nombre;
    int ruc;
    char *direccion;
    int numBuses;
    Omnibus flota[50];
    void separaPalabras (char* ,char**, int&);
    void agregarPasajero (Pasajero *);
    int buscarFlotaDestino (char*, int, int&, int&);
    void printNChar(char, int, int = 1);
};

#endif	/* EMPRESA_H */

