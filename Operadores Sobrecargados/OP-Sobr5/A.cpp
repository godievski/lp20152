#include "A.h"

A::A(float cx){
    x=cx;
}

void A::setX(float cx){
    x=cx;
}

float A::getX(void){
    return x;
}


A A::operator ++ (void){  //como prefijo
    x=x*x;
    return *this;
}

A A::operator ++ (int){  //como sufijo
    A aux=*this;
    x=x*x;
    return aux;
}

