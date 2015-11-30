/* 
 * File:   Empresa.cpp
 * Author: alulab14
 * 
 * Created on 27 de noviembre de 2015, 07:58 AM
 */


/*
 NOMBRE: DIEGO ALONSO GUARDIA AYALA
 * COD: 20125849
 */
#include "Empresa.h"
#include <cstdlib>
#include <cstring>

Empresa::Empresa() {
    nombre = NULL;
    codigo = 0;
}

Empresa::~Empresa(){
    delete nombre;
}

void Empresa::SetNombre(char* nombre) {
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre,nombre);
}

void Empresa::GetNombre(char *nombre) const {
    strcpy(nombre,this->nombre);
}

void Empresa::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Empresa::GetCodigo() const {
    return codigo;
}


ifstream& operator >> (ifstream& in, Empresa& emp)
{
    int cod;
    char nombre[200];
    if (in >> cod){
        emp.codigo = cod;
        in >> cod; //borra espacios en blanco
        in.clear();
        in.getline(nombre, 200);
        emp.SetNombre(nombre);
    }
    return in;
}

ostream& operator << (ostream& cout, Empresa& emp)
{
    cout << left << setw(10) << emp.codigo << right  << emp.nombre << endl;
    return cout;
}

Empresa& Empresa::operator = (Empresa& emp)
{
    if (this != &emp){
        codigo = emp.codigo;
        SetNombre(emp.nombre);
        llamadas = emp.llamadas;
    }
    return *this;
}

int Empresa::operator > (Empresa & emp)
{
    return strcmp(nombre,emp.nombre) > 0;
}

int Empresa::operator == (Empresa& emp)
{
    /*COMPARA SOLO EL CODIGO*/
    return codigo == emp.codigo;
}

void Empresa::agregarLlamada (Llamada & llam)
{
    int ind;
    Llamada *ptrLlam;
    if ((ind = llamadas.buscar(llam)) != -1){
        /*ENCONTRÓ LA LLAMADA*/
        if (!llamadas.obtener(ind,ptrLlam)){
            cerr << "No se pudo obtener el indice: "<< ind << endl;
            exit(1);
        }
        *ptrLlam += llam;
    } else
        llamadas.insertar(llam);
}

void Empresa::impLlamadas (void)
{
    int cantLlam = llamadas.length();
    Llamada *llam;
    for (int i = 0; i < cantLlam; i++){
        llamadas.obtener(i, llam);
        cout << *llam;
    }
}

double Empresa::obtenerTotal(double* costos)
{
    double total = 0;
    int codigo;
    Llamada* llam;
    for (int i = 0; i < llamadas.length(); i++){
        llamadas.obtener(i, llam);
        codigo = llam->GetCodPais();
        total += costos[codigo] * llam->GetTiempo();
    }
    return total;
}