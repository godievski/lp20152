/* 
 * File:   Cilindro.cpp
 * Author: Usuario
 * 
 * Created on 10 de noviembre de 2015, 09:21 AM
 */

#include "Cilindro.h"

Cilindro::Cilindro() {
}

Cilindro::Cilindro(const Cilindro& orig) {
}

Cilindro::~Cilindro() {
   
}

double Cilindro::volumen (void)
{
    return Circulo::area() * altura;
}

double Cilindro::area (void)
{
    //return 2*(PI*GetRadio()*GetRadio()) + altura*(perimetro());
    return 2*(Circulo::area()) + altura*(perimetro());
}

void Cilindro::setAltura(double altura) {
    this->altura = altura;
}

double Cilindro::getAltura() const {
    return altura;
}

void Cilindro::imprime(void) {
    cout << "Clase Cilindro" << endl;
    Circulo::imprime();
    cout << "Altura = " << altura << endl;
}
