/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 27 de noviembre de 2015, 07:57 AM
 */

/*
 NOMBRE: DIEGO ALONSO GUARDIA AYALA
 * COD: 20125849
 */

#include <cstdlib>
#include "Lista.h"
#include "Corporacion.h"
#include <iostream>
#include <fstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Corporacion miCop;
    
    ifstream archEmp ("Empresas.txt", ios::in);
    if (!archEmp){
        cerr << "No se pudo abrir el archivo Empresas.txt" << endl;
        exit(1);
    }
    miCop.leerEmpresas(archEmp);
    
    ifstream archLlam ("Llamadas.txt", ios::in);
    if (!archLlam){
        cerr << "No se pudo abrir el archivo Llamadas.txt" << endl;
        exit(1);
    }
    miCop.leerLlamadas(archLlam);
    miCop.impEmp();
    
    return 0;
}

