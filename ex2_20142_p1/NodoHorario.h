/* 
 * File:   NodoHorario.h
 * Author: Usuario
 *
 * Created on 30 de noviembre de 2015, 09:50 AM
 */

#ifndef NODOHORARIO_H
#define	NODOHORARIO_H

#include <list>
#include "Evento.h"
#include <iostream>
#include <iomanip>
using namespace std;

class NodoHorario {
public:
    NodoHorario();
    NodoHorario(char*, char*, int);
    friend ostream& operator << (ostream&, NodoHorario*);
private:
    char* codigo;
    char* profesor;
    int alumnos;
    list <Evento> eventos;
    NodoHorario* sgte;
    friend class ListaCursos;
};

#endif	/* NODOHORARIO_H */

