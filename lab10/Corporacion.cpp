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
    for (int i = 0; i < tam; i++){
        empresas.obtener(i, ptrEmp);
        cout << *ptrEmp;
        ptrEmp->impLlamadas();
    }
}

void Corporacion::leerCostos (ifstream& arch, double*costos)
{
    /*FALTA IMPLEMENTAR*/
    int cod;
    double costo;
    while (arch >> cod){
        arch >> costo;
        costos[cod] = costo;
    }
}

void Corporacion::impReporte (ifstream& arch)
{
    double total;
    char nomb[200];
    Empresa *emp;
    double costos[500];
    
    leerCostos(arch, costos);
    cout.precision(2);
    for (int i = 0; i < empresas.length(); i++){
        empresas.obtener(i, emp);
        total = emp->obtenerTotal(costos);
        cout << "CODIGO: " << emp->GetCodigo() << endl;
        emp->GetNombre(nomb);
        cout << "NOMBRE: " << nomb << endl;
        cout << "Monto por llamadas: S/. " << fixed << setw(8) << total << endl;
        for (int j = 0; j < 50 ; j++) cout << '=';
        cout << endl;
    }
}