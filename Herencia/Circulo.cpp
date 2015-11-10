/* 
 * File:   Circulo.cpp
 * Author: Usuario
 * 
 * Created on 10 de noviembre de 2015, 09:15 AM
 */

#include "Circulo.h"

Circulo::Circulo(void) {
    radio = 0;
}

Circulo::Circulo(double r) {
    radio = r;
}

Circulo::~Circulo() {
    
}

void Circulo::SetRadio(double radio) {
    this->radio = radio;
}

double Circulo::GetRadio() const {
    return radio;
}

void Circulo::imprime (void){
    cout << "Circulo: " << radio << endl;
}

double Circulo::area (void){
    return PI*radio*radio;
}

double Circulo::perimetro (void)
{
    return PI*2*radio;
}
