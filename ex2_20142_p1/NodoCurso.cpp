/* 
 * File:   NodoCurso.cpp
 * Author: Usuario
 * 
 * Created on 30 de noviembre de 2015, 09:50 AM
 */

#include "NodoCurso.h"
#include <cstdlib>
#include <cstring>

NodoCurso::NodoCurso() {
    codigo = nombre = NULL;
    inicio = fin = NULL;
    longitud = 0;
    sgte = NULL;
}

NodoCurso::NodoCurso(char*codigo, char*nombre, double creditos){
    this->codigo = new char[strlen(codigo)+1];
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->codigo, codigo);
    strcpy(this->nombre, nombre);
    this->creditos = creditos;
    inicio = fin = NULL;
    longitud = 0;
    sgte = NULL;
}

ostream& operator << (ostream& cout, NodoCurso* curso)
{
    cout.precision(1);
    cout << "CODIGO: " << curso->codigo << endl;
    cout << "NOMBRE: " << curso->nombre << endl;
    cout << "CREDITOS: " << fixed << setw(5) << curso->creditos << endl;
    return cout;
}

ifstream& operator >> (ifstream& arch, NodoCurso& curso)
{
    char codigo[10],nombre[100];
    double creditos;
    if (arch>>codigo){
        curso.leeNombreYCred(arch, nombre, creditos);
        curso.SetCodigo(codigo);
        curso.SetNombre(nombre);
        curso.creditos = creditos;
    }
    return arch;
}

void NodoCurso::leeNombreYCred(ifstream& arch, char* nombre, double& creditos)
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

void NodoCurso::SetCodigo(char* codigo)
{
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
}
   
void NodoCurso::SetNombre(char* nombre)
{
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}
    
void NodoCurso::GetCodigo(char* codigo)
{
    strcpy(codigo, this->codigo);
}
    
void NodoCurso::GetNombre(char* nombre)
{
    strcpy(nombre, this->nombre);
}