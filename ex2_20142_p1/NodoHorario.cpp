/* 
 * File:   NodoHorario.cpp
 * Author: Usuario
 * 
 * Created on 30 de noviembre de 2015, 09:50 AM
 */

#include "NodoHorario.h"
#include <cstdlib>
#include <cstring>

NodoHorario::NodoHorario() {
    codigo = profesor = NULL;
    sgte = NULL;
}

NodoHorario::NodoHorario(char*codigo, char*profesor, int alumnos)
{
    this->codigo = new char[strlen(codigo)+1];
    this->profesor = new char[strlen(profesor)+1];
    strcpy(this->codigo, codigo);
    strcpy(this->profesor, profesor);
    this->alumnos = alumnos;
    sgte = NULL;
}

ostream& operator << (ostream& cout, NodoHorario* horario)
{
    list<Evento>::iterator indEvent;
    char dia[10], aula[10];
    int hI, hF;
    
    cout << left << setw(10) << horario->codigo
         << left << setw(20) << horario->profesor
         << "     "<< left << setw(10) << horario->alumnos;
    if (!horario->eventos.empty()){
        /*IMPRIME ALGO*/
        indEvent = horario->eventos.begin();
        (*indEvent).GetAula(aula);
        (*indEvent).GetDia(dia);
        hI = (*indEvent).GetHoraIni();
        hF = (*indEvent).GetHoraFin();
        cout << dia << ' ' << right << setw(2) << hI 
             << " - " << right << setw(2) << hF << ' ' << aula << endl;
        indEvent++;
        for (indEvent =indEvent;indEvent != horario->eventos.end(); indEvent++){
            (*indEvent).GetAula(aula);
            (*indEvent).GetDia(dia);
            hI = (*indEvent).GetHoraIni();
            hF = (*indEvent).GetHoraFin();
            cout << setw(45) << " ";
            cout << dia << ' ' << right << setw(2) << hI 
                 << " - " << right << setw(2) << hF << ' ' << aula << endl;
        }
    }
    return cout;
}
