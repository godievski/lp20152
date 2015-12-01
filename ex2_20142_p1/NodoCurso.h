/* 
 * File:   NodoCurso.h
 * Author: Usuario
 *
 * Created on 30 de noviembre de 2015, 09:50 AM
 */

#ifndef NODOCURSO_H
#define	NODOCURSO_H

#include "NodoHorario.h"
#include "funAux.h"
#include <iostream>
#include <iomanip>
using namespace std;

class NodoCurso {
public:
    NodoCurso();
    NodoCurso(char*, char*, double);
    friend ostream& operator << (ostream&, NodoCurso*);
    friend ifstream& operator >> (ifstream&, NodoCurso&);
    void SetCodigo(char* codigo);
    void SetNombre(char* nombre);
    void GetCodigo(char* codigo);
    void GetNombre(char* nombre);
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
    void leeNombreYCred(ifstream&, char*, double&);
};

#endif	/* NODOCURSO_H */

