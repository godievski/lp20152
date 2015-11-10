#include <stdio.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include "Persona.h"
using namespace std;

void Persona::leerDatos(void){
    char nomb[50];
    printf("DNI   : "); scanf("%d", &dni);
    while(getchar()!='\n');
    printf("Nombre: "); gets(nomb);
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre, nomb);
    printf("Sueldo: "); scanf("%f", &sueldo);
}

void Persona::imprimeDatos(void){
    printf("%10d %-20s %10.2f\n", dni, nombre, sueldo);
}

ostream & operator << (ostream & out, Persona &p){
    out << setw(10)<<p.dni<<setw(20)<<p.nombre<<setw(15)<<p.sueldo<<endl;
}

istream & operator >>(istream & in, Persona &p){
    char nomb[20],c;
    cout<<"DNI: ";
    cin >> p.dni;
    while (cin.get()!='\n');
    cout<<"NOMBRE: ";
    cin.getline(nomb,50);
    p.nombre = new char[strlen(nomb)+1];
    strcpy(p.nombre, nomb);
    cout<<"SUELDO: ";
    cin>>p.sueldo;
}
