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
#include <fstream>
#include <iomanip>
#include "funAux.h"
using namespace std;

class NodoHorario {
public:
    NodoHorario();
    NodoHorario(char*, char*, int);
    friend ostream& operator << (ostream&, NodoHorario*);
    friend ifstream& operator >> (ifstream&, NodoHorario&);
    void SetCodigo(char* codigo);
    void SetProfesor(char* profesor);
    void GetCodigo(char* codigo);
    void GetProfesor(char* profesor);
private:
    char* codigo;
    char* profesor;
    int alumnos;
    list <Evento> eventos;
    NodoHorario* sgte;
    friend class ListaCursos;
    void leeEventos(ifstream&, Evento*, int&);
    void insertarEventos (Evento*, int);
};

#endif	/* NODOHORARIO_H */

