#include "Reloj.h"

Reloj::Reloj(int h, int m, int s){
    hora=h;
    minuto=m;
    segundo=s;
}

void Reloj::DefineTiempo(int h, int m, int s){
    hora=h;
    minuto=m;
    segundo=s;
}

void Reloj::DefineHora(int h){
    hora = h;
}

void Reloj::DefineMinuto(int m){
    minuto = m;
}

void Reloj::DefineSegundo(int s){
    segundo = s;
}

int Reloj::Hora(void){
    return hora;
}

int Reloj::Minuto(void){
    return minuto;
}

int Reloj::Segundo(void){
    return segundo;
}

void Reloj::operator ++(void){
    segundo++;
    if (segundo > 59){
        segundo = 0;
        ++minuto;
    }
    if (minuto > 59){
        minuto = 0;
        ++hora;
    }

    if (hora > 23)  hora = 0;
}
