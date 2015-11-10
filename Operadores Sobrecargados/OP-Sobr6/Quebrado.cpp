#include <stdio.h>
#include "Quebrado.h"

Quebrado::Quebrado(int n, int d){
    numerador = n;
    denominador = d;
}

void Quebrado::setNum(int n){
    numerador = n;
}

void Quebrado::setDen(int d){
    denominador = d;
}

int Quebrado::getNum(void){
    return numerador;
}

int Quebrado::getDen(void){
    return denominador;
}

void Quebrado::muestra(void){
    printf("%d/%d\n", numerador, denominador);
}

Quebrado Quebrado::simplifica(void){
    int mcd, temp, resto;

    //Algoritmo de Euclides
    mcd = (numerador>= 0) ? numerador : -numerador;
    temp = (denominador>= 0) ? denominador : -denominador;

    while (temp > 0){
        resto = mcd % temp;
        mcd = temp;
        temp = resto;
    }
    if (mcd > 1){
        numerador /= mcd;
        denominador /= mcd;
    }
    return *this;
}

Quebrado Quebrado::operator = (Quebrado  q){
    numerador = q.getNum();
    denominador = q.getDen();
    return *this;
}

Quebrado Quebrado::operator += (Quebrado q){
    numerador = numerador*q.denominador + q.numerador*denominador;
    denominador = denominador*q.denominador;
    return this->simplifica();
}

Quebrado Quebrado::operator -= (Quebrado q){
    numerador = numerador*q.denominador - q.numerador*denominador;
    denominador = denominador*q.denominador;
    return this->simplifica();
}

Quebrado::operator float(){
    return float(numerador)/float(denominador);
}

Quebrado operator + (Quebrado q1, Quebrado q2){
    Quebrado Aux;
    Aux.numerador = q1.numerador * q2.denominador +
                    q2.numerador * q1.denominador ;

    Aux.denominador = q1.denominador * q2.denominador;

    return Aux;
}

Quebrado operator - (Quebrado q1, Quebrado q2){
    Quebrado Aux;

    Aux.numerador = q1.numerador * q2.denominador -
                    q2.numerador * q1.denominador;

    Aux.denominador = q1.denominador * q2.denominador;

    return Aux;
}

