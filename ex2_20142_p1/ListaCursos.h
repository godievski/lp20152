/* 
 * File:   ListaCursos.h
 * Author: Usuario
 *
 * Created on 30 de noviembre de 2015, 09:49 AM
 */

#ifndef LISTACURSOS_H
#define	LISTACURSOS_H

#include "Evento.h"
#include "NodoCurso.h"
#include "NodoHorario.h"
#include <list>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

class ListaCursos {
public:
    ListaCursos();
    void leerCursos(ifstream& arch);
    void leerHorarios(ifstream& arch);
    void impReporte(void);
    void insertar(NodoCurso*);
    void insertar(char*, NodoHorario*);
private:
    NodoCurso* inicio;
    NodoCurso* fin;
    int longitud;
    void leeNombreYCred(ifstream&,char*,double&);
    void leeEventos(ifstream&, Evento*, int&);
    void insertarEventos(NodoHorario*, Evento*, int);
    void separaPalabras(char* linea, char** palabras, int& cantPal);
    void impCabecera (void);
};

#endif	/* LISTACURSOS_H */

