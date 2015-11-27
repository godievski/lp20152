/* 
 * File:   Corporacion.cpp
 * Author: alulab14
 * 
 * Created on 27 de noviembre de 2015, 07:58 AM
 */

/*
 NOMBRE: DIEGO ALONSO GUARDIA AYALA
 * COD: 20125849
 */

#include "Corporacion.h"

void Corporacion::leerEmpresas (ifstream& arch)
{
    Empresa emp;
    while (arch >> emp)
        empresas.insertar(emp);
}

void Corporacion::leerLlamadas (ifstream& arch)
{
    Llamada llam;
    Empresa emp;
    Empresa* ptrEmp;
    int codigo, ind;
    while (arch >> codigo){
        arch >> llam;
        emp.SetCodigo(codigo);
        ind = empresas.buscar(emp);
        empresas.obtener(ind, ptrEmp);
        ptrEmp->agregarLlamada(llam);
    }
}


void Corporacion::impEmp (void)
{
    Empresa *ptrEmp;
    int tam = empresas.length();
    int cod;
    char nombre[200];
    for (int i = 0; i < tam; i++){
        empresas.obtener(i, ptrEmp);
        cout << *ptrEmp;
        ptrEmp->impLlamadas();
    }
}