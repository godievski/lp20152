/* 
 * File:   Corporacion.h
 * Author: alulab14
 *
 * Created on 27 de noviembre de 2015, 07:58 AM
 */

/*
 NOMBRE: DIEGO ALONSO GUARDIA AYALA
 * COD: 20125849
 */

#ifndef CORPORACION_H
#define	CORPORACION_H

#include "Lista.h"
#include "Empresa.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Corporacion {
public:
    void leerEmpresas (ifstream&);
    void leerLlamadas (ifstream&);
    void impReporte (ifstream&);
    void impEmp (void);
private:
    Lista <Empresa> empresas;
    void leerCostos (ifstream &, double*);
};

#endif	/* CORPORACION_H */

