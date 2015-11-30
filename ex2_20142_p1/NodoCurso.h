/* 
 * File:   NodoCurso.h
 * Author: Usuario
 *
 * Created on 30 de noviembre de 2015, 09:50 AM
 */

#ifndef NODOCURSO_H
#define	NODOCURSO_H

#include "NodoHorario.h"
#include <iostream>
#include <iomanip>
using namespace std;

class NodoCurso {
public:
    NodoCurso();
    NodoCurso(char*, char*, double);
    friend ostream& operator << (ostream&, NodoCurso*);
private:
    char* codigo;
    char* nombre;
    double creditos;
    /*LISTA HORARIO*/
    NodoHorario* inicio;
    NodoHorario* fin;
    int longitud;
    /*FIN LISTA HORARIO*/
    NodoCurso* sgte;
    friend class ListaCursos;
};

#endif	/* NODOCURSO_H */

