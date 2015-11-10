/* 
 * File:   RegistroPersonal.h
 * Author: Usuario
 *
 * Created on 5 de noviembre de 2015, 03:37 PM
 */

#ifndef REGISTROPERSONAL_H
#define	REGISTROPERSONAL_H

#include <fstream>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include "Medico.h"
using namespace std;

void inicializar (fstream &arch);

void cargarMedicos (fstream &arch);

void listar (fstream &arch);
#endif	/* REGISTROPERSONAL_H */

