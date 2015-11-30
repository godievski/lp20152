/* 
 * File:   Empresa.h
 * Author: alulab14
 *
 * Created on 27 de noviembre de 2015, 07:58 AM
 */

/*
 NOMBRE: DIEGO ALONSO GUARDIA AYALA
 * COD: 20125849
 */

#ifndef EMPRESA_H
#define	EMPRESA_H

#include "Lista.h"
#include "Llamada.h"
#include <iostream>
#include <fstream>
using namespace std;

class Empresa {
public:
    Empresa();
    virtual ~Empresa();
    void SetNombre(char* nombre);
    void GetNombre(char* ) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    friend ifstream& operator >> (ifstream&, Empresa&);
    friend ostream& operator << (ostream&, Empresa&);
    Empresa& operator = (Empresa&);
    int operator == (Empresa&);
    int operator > (Empresa &);
    void agregarLlamada (Llamada &);
    void impLlamadas (void);
    double obtenerTotal (double*);
private:
    int codigo;
    char* nombre;
    Lista<Llamada> llamadas;
};

#endif	/* EMPRESA_H */

