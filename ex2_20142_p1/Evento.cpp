/* 
 * File:   Evento.cpp
 * Author: Usuario
 * 
 * Created on 30 de noviembre de 2015, 09:55 AM
 */

#include "Evento.h"
#include <cstring>

Evento::Evento(){
    horaIni = horaFin = 0;
}

Evento::Evento(char* dia,int hI,int hF,char* aula)
{
    SetDia(dia);
    SetAula(aula);
    horaIni = hI;
    horaFin = hF;
}

void Evento::SetAula(char* aula) {
    strcpy(this->aula,aula);
}

void Evento::GetAula(char* aula) const {
    strcpy(aula,this->aula);
}

void Evento::SetHoraFin(int horaFin) {
    this->horaFin = horaFin;
}

int Evento::GetHoraFin() const {
    return horaFin;
}

void Evento::SetHoraIni(int horaIni) {
    this->horaIni = horaIni;
}

int Evento::GetHoraIni() const {
    return horaIni;
}

void Evento::SetDia(char* dia) {
    strcpy(this->dia, dia);
}

void Evento::GetDia(char* dia) const {
    strcpy(dia, this->dia);
}

int Evento::convertDia(void)
{
    if (strcmp(dia, "LUN") == 0)
        return 1;
    else if (strcmp(dia, "MAR") == 0)
        return 2;
    else if (strcmp(dia, "MIE") == 0)
        return 3;
    else if (strcmp(dia, "JUE") == 0)
        return 4;
    else if (strcmp(dia, "VIE") == 0)
        return 5;
    else if (strcmp(dia, "SAB") == 0)
        return 6;
    else if (strcmp(dia, "DOM") == 0)
        return 7;
    else return 8;
}

bool Evento::operator < (Evento& other)
{
    return convertDia() < other.convertDia();
}