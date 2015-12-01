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

ifstream& operator >> (ifstream& arch, NodoHorario& horario)
{
    char codigo[10], profesor[100];
    int alumnos;
    Evento eventos[20];
    int cantEventos;
    arch>>codigo;
    arch>>profesor;
    arch>>alumnos;
    horario.SetCodigo(codigo);
    horario.SetProfesor(profesor);
    horario.alumnos = alumnos;
    horario.leeEventos(arch, eventos, cantEventos);
    horario.insertarEventos(eventos, cantEventos);
    return arch;
}

void NodoHorario::leeEventos(ifstream& arch, Evento* eventos, int& cantEventos)
{
    char linea[1000];
    char *palabras[100];
    int cantPal;
    arch.getline(linea,1000);
    
    cantEventos = 0;
    separaPalabras(linea, palabras, cantPal);
    /*PRIMER EVENTO QUE SIEMPRE HAY*/
    eventos[0].SetDia(palabras[0]);
    eventos[0].SetHoraIni(atoi(palabras[1]));
    //palabras[2] == TRASH
    eventos[0].SetHoraFin(atoi(palabras[3]));
    eventos[0].SetAula(palabras[4]);
    cantEventos++;
    /*FIN DEL PRIMER EVENTO*/
    
    /*COMPLETAR OTROS EVENTOS SI LO HUBIESEN*/
    for (int i = 5; i < cantPal; i+=6){
        eventos[cantEventos].SetDia(palabras[i+1]);
        eventos[cantEventos].SetHoraIni(atoi(palabras[i+2]));
        eventos[cantEventos].SetHoraFin(atoi(palabras[i+4]));
        eventos[cantEventos].SetAula(palabras[i+5]);    
        cantEventos++;
    }
}

void NodoHorario::insertarEventos(Evento* eventos, int cantEventos)
{
    for (int i = 0; i < cantEventos; i++)
        this->eventos.push_back(eventos[i]);
}

void NodoHorario::SetCodigo(char* codigo)
{
    this->codigo = new char[strlen(codigo)+1];
    strcpy(this->codigo, codigo);
}
    
void NodoHorario::SetProfesor(char* profesor)
{
    this->profesor = new char[strlen(profesor)+1];
    strcpy(this->profesor, profesor);
}
    
void NodoHorario::GetCodigo(char* codigo)
{
    strcpy(codigo, this->codigo);
}
    
void NodoHorario::GetProfesor(char* profesor)
{
    strcpy(profesor, this->profesor);
}