/* 
 * File:   Circulo.h
 * Author: Usuario
 *
 * Created on 10 de noviembre de 2015, 09:15 AM
 */

#ifndef CIRCULO_H
#define	CIRCULO_H

#include <iostream>
using namespace std;

#define PI 3.141592

class Circulo {
public:
    Circulo(void);
    Circulo(double);
    virtual ~Circulo();
    void SetRadio(double radio);
    double GetRadio() const;
    void imprime (void);
    double area (void);
    double perimetro (void);
private:
    double radio;
};

#endif	/* CIRCULO_H */

