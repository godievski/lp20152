/* 
 * File:   ListaCursos.cpp
 * Author: Usuario
 * 
 * Created on 30 de noviembre de 2015, 09:49 AM
 */

#include "ListaCursos.h"
#include <cstdlib>
#include <cstring>

ListaCursos::ListaCursos() {
    inicio = fin = NULL;
    longitud = 0;
}

void ListaCursos::leerCursos(ifstream& arch)
{
    char codigo[10],nombre[100];
    double creditos;
    NodoCurso *curso;
    while (arch >> codigo){
        leeNombreYCred(arch,nombre,creditos);
        curso = new NodoCurso(codigo,nombre,creditos);
        insertar(curso);
    }
}

void ListaCursos::leerCursosVer2(ifstream& arch)
{
    NodoCurso *curso;
    while (1){
        curso = new NodoCurso;
        if (!(arch >> (*curso))){
            delete curso;
            break;
        }
        insertar(curso);
    }
}


void ListaCursos::leerHorariosVer2(ifstream& arch)
{
    char codigoCurso[10];
    NodoHorario* horario;
    while (arch>>codigoCurso){
        horario = new NodoHorario;
        arch >> (*horario);
        horario->eventos.sort();
        insertar(codigoCurso, horario);
    }
}

void ListaCursos::insertar(NodoCurso* curso)
{
    /*INSERTAR SIN ORDENAR*/
//    if (fin == NULL || inicio == NULL)
//        inicio = curso;
//    else
//        fin->sgte = curso;
//    fin = curso;
//    longitud++;
    
    /*INSERTAR ORDENADO POR CODIGO*/
    NodoCurso* cursoAct = inicio;
    NodoCurso* curAnt = NULL;
    while (cursoAct != NULL){
        if (strcmp(cursoAct->codigo,curso->codigo) > 0) break;
        curAnt = cursoAct;
        cursoAct = cursoAct->sgte;
    }
    if (curAnt == NULL)
        inicio = curso;
    else
        curAnt->sgte = curso;
    curso->sgte = cursoAct;
    longitud++;
}
    
void ListaCursos::leeNombreYCred(ifstream& arch, char* nombre, double& creditos)
{
    char linea[200];
    char *palabras[20];
    int cantPal = 0;
    arch.getline(linea,200);
    /*SEPARA PALABRAS*/
    separaPalabras(linea,palabras,cantPal);
    /*FIN SEPARA PALABRAS*/
    creditos = atof(palabras[cantPal-1]);
    strcpy(nombre, palabras[0]);
    for (int i = 1; i < cantPal-1; i++){
        strcat(nombre, " ");
        strcat(nombre, palabras[i]);
    }
}

void ListaCursos::leerHorarios(ifstream& arch)
{
    char codigoCurso[10], codigoHorario[10], profesor[100];
    int alumnos;
    NodoHorario* horario;
    Evento eventos[20];
    int cantEventos;
    while (arch>>codigoCurso){
        arch>>codigoHorario;
        arch>>profesor;
        arch>>alumnos;
        leeEventos(arch, eventos, cantEventos);
        horario = new NodoHorario (codigoHorario, profesor, alumnos);
        insertarEventos(horario, eventos, cantEventos);
        horario->eventos.sort();
        insertar(codigoCurso, horario);
    }
    
}
    
void ListaCursos::insertar(char* codigoCurso, NodoHorario* horario)
{
    NodoCurso* curso = inicio;
    /*BUSCA EL CURSO*/
    while (curso != NULL){
        if (strcmp(curso->codigo,codigoCurso) == 0)
            break;
        curso = curso->sgte;
    }
    /*INSERTA SIN ORDENAR*/
//    if (curso != NULL){
//        if (curso->fin == NULL || curso->inicio == NULL)
//            curso->inicio = horario;
//        else
//            curso->fin->sgte = horario;
//        curso->fin = horario;
//        (curso->longitud)++;
//    }
    
    /*INSERTA ORDENADO POR CODIGO*/
    if (curso != NULL){
        NodoHorario* horAct = curso->inicio;
        NodoHorario* horAnt = NULL;
        while (horAct != NULL){
            if (strcmp(horAct->codigo,horario->codigo) > 0) break;
            horAnt = horAct;
            horAct = horAct->sgte;
        }
        if (horAnt == NULL)
            curso->inicio = horario;
        else
            horAnt->sgte = horario;
        horario->sgte = horAct;
        (curso->longitud)++;
    }
}

void ListaCursos::leeEventos(ifstream& arch, Evento* eventos, int& cantEventos)
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

void ListaCursos::insertarEventos(NodoHorario* horario, Evento* eventos,
                                  int cantEventos)
{
    for (int i = 0; i < cantEventos; i++)
        horario->eventos.push_back(eventos[i]);
}

void ListaCursos::impReporte(void)
{
    NodoCurso* curso = inicio;
    NodoHorario* horario;
    for (int i = 0; i < longitud; i++){
        cout << curso;
        horario = curso->inicio;
        impCabecera();
        for (int j = 0; j < curso->longitud; j++){
            cout << horario;
            horario = horario->sgte;
        }
        cout << endl;
        curso = curso->sgte;
    }
}

void ListaCursos::impCabecera (void)
{
    for (int j = 0; j < 80; j++) cout << '=';
    cout << endl;
        
    cout << left << setw(10) << "HORARIO"
         << left << setw(20) << "PROFESOR"
         << left << setw(15) << "#MATRICULADOS"
         << left << setw(30) << "CLASES" << endl;
    
    for (int j = 0; j < 80; j++) cout << '=';
    cout << endl;
}
    
void ListaCursos::operator << (char* codigo)
{
    NodoCurso* curso = inicio;
    NodoHorario* horario;
    for (int i = 0; i < longitud; i++){
        if (strcmp(curso->codigo,codigo) == 0) break;
        curso = curso->sgte;
    }
    if (curso){
        cout << curso;
        horario = curso->inicio;
        impCabecera();
        for (int i = 0; i < curso->longitud; i++){
            cout << horario;
            horario = horario->sgte;
        }
        cout << endl;
        curso = curso->sgte;
    }
}