/* 
 * File:   Omnibus.h
 * Author: Usuario
 *
 * Created on 19 de noviembre de 2015, 02:46 PM
 */

#ifndef OMNIBUS_H
#define	OMNIBUS_H

#include "Vehiculo.h"
#include "Pasajero.h"


class Omnibus: public Vehiculo {
public:
    Omnibus();
    virtual ~Omnibus();
    void SetPasajeros (int);
    void agregarPasajero (Pasajero*, int);
    int disponibilidad (void);
    int verificaDestino (char*, int&);
    void impDatos (void);
private:
    void *pasajeros;
    int cantPas;
    friend class Empresa;
};

#endif	/* OMNIBUS_H */

