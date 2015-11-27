/* 
 * File:   funAux.h
 * Author: alulab14
 *
 * Created on 13 de noviembre de 2015, 09:06 AM
 */

/*
 * Nombres: DIEGO ALONSO GUARDIA AYALA
 * Codigo: 20125849
 */


#ifndef FUNAUX_H
#define	FUNAUX_H

#include <fstream>
#include <iostream>
#include "Cadena.h"
using namespace std;

void leeNombres (ifstream &arch, Cadena *personas, int &cant);
void ordenaNombres (Cadena *personas, int cant);
void impNombres (Cadena *personas, int cant);

#endif	/* FUNAUX_H */

