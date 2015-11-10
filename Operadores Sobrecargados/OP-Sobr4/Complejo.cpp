#include "Complejo.h"

Complejo::Complejo(float r, float i){
    real=r;  imag=i;
}

void Complejo::setReal(float r){
    real=r;
}

void Complejo::setImaginario(float i){
    imag=i;
}

float Complejo::getReal(void){
    return real;
}

float Complejo::getImaginario(void){
    return imag;
}

Complejo Complejo::operator + (Complejo C){
    return Complejo(real+C.real , imag+C.imag);
}

////   si no hay constructor
//Complejo Complejo::operator + (Complejo C){
//    Complejo aux;
//    aux.real = real + C.real;
//    aux.imag = imag + C.imag;
//
//    return aux;
//}

Complejo Complejo::operator - (Complejo C){
    return Complejo(real-C.real , imag-C.imag);
}

Complejo Complejo::operator += (Complejo C){
    real += C.real;
    imag += C.imag;
    return *this;
}

