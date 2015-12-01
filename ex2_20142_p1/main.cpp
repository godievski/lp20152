/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 28 de noviembre de 2015, 09:16 PM
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include "ListaCursos.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    ListaCursos miLista;
    
    ifstream cursos ("cursos.txt", ios::in);
    if (!cursos){
        cerr << "No se pudo abrir cursos.txt\n";
        exit(1);
    }
    
    miLista.leerCursosVer2(cursos);
    
    ifstream horarios ("horarios.txt", ios::in);
    if (!horarios){
        cerr << "No se pudo abrir horarios.txt\n";
        exit(1);
    }
    
    miLista.leerHorariosVer2(horarios);
    
    //miLista.impReporte();
    miLista << "INF220";
    return 0;
}

