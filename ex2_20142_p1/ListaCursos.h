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
#include "funAux.h"
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
    /*SEGUNDA VERSION DE LEER*/
    void leerCursosVer2(ifstream& arch);
    void leerHorariosVer2(ifstream& arch);
    /*FIN SEGUNDA VERSION*/
    void operator << (char*);
private:
    NodoCurso* inicio;
    NodoCurso* fin;
    int longitud;
    void leeNombreYCred(ifstream&,char*,double&); //METEODO DUPLICADO VER 1
    void leeEventos(ifstream&, Evento*, int&); //METODO DUPLICADO VER 1
    void insertarEventos(NodoHorario*, Evento*, int); //METODO DUPLICADO VER 1
    void impCabecera (void);
};

#endif	/* LISTACURSOS_H */

