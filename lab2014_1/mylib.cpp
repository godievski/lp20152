#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include "mylib.h"
#include "ClsCursos.h"
#include "funAux.h"
using namespace std;

#define MAX_LINEA 200

void * leeDatosCursos (void)
{
    char linea[MAX_LINEA];
    void *buffCursos[200];
    int cantCursos = 0;
    
    ifstream archCurso ("Cursos.txt", ios::in);
    ofstream testCurso ("Testing.txt", ios::out);
//    ofstream testCurso ("Test_Cursos.txt", ios::out);
    if (!archCurso){
        cout << "Error al abrir archivo." << endl;
        exit(1);
    }
    int ex = 0;
    while (archCurso.getline(linea, MAX_LINEA)){
        char codigo[10], nombre[100], *palabras[30];
        double cred;
        int cantPal;
        separaPalabras(linea,palabras, cantPal);
        strcpy(codigo, palabras[0]);
        cred = atof(palabras[cantPal - 1]);
        strcpy(nombre, palabras[1]);
        for (int i = 2; i < cantPal - 1; i++){
            strcat(nombre, " ");
            strcat(nombre, palabras[i]);
        }
//        cout << "Codigo: " << codigo << endl;
//        cout << "Cursos: " << nombre << endl;
//        cout << "Creditos: " << cred << endl;
//        cout << "--------------------------------------------------" << endl;
        ClsCursos *curso = new ClsCursos;
        curso->SetCodigo(codigo);
        curso->SetNombre(nombre);
        curso->SetCreditos(cred);
        buffCursos[cantCursos] = curso;
        cantCursos++;
        ex++;
        curso->impDatos(testCurso);
        //if (ex == 100) break;
    }
    return NULL;
    cout << "HOLA" << endl;
    void **arrayCursos = new void*[cantCursos + 1];
    for (int i = 0; i < cantCursos; i++)
        arrayCursos[i] = buffCursos[i];
    arrayCursos[cantCursos] = NULL;
    return (void *)arrayCursos;
}

void impCursos (void *cursos)
{
    void **arrayCursos = (void **) cursos;
    ofstream testCurso ("Test_Cursos.txt", ios::out);

    for (int i = 0; arrayCursos[i]; i++){
        ClsCursos* curso = (ClsCursos*) arrayCursos[i];
        curso->impDatos(testCurso);
    }
}
