/* 
 * File:   Llamada.h
 * Author: alulab14
 *
 * Created on 27 de noviembre de 2015, 07:58 AM
 */

/*
 NOMBRE: DIEGO ALONSO GUARDIA AYALA
 * COD: 20125849
 */

#ifndef LLAMADA_H
#define	LLAMADA_H

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#define DIGITOS 13

class Llamada {
public:
    Llamada();
    void SetTiempo(double tiempo);
    double GetTiempo() const;
    void SetNumero(char*);
    void GetNumero(char*) const;
    friend ifstream& operator >> (ifstream&, Llamada&);
    Llamada& operator = (Llamada&);
    int operator == (Llamada&);
    int operator > (Llamada &);
    void operator += (Llamada &);
    friend ostream& operator << (ostream&, Llamada&);
private:
    char numero[DIGITOS];
    double tiempo;
};

#endif	/* LLAMADA_H */

