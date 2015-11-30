/* 
 * File:   Tablero.cpp
 * Author: Usuario
 * 
 * Created on 28 de noviembre de 2015, 10:08 PM
 */

#include "Tablero.h"
#include <cstdlib>
#include <cstring>

Tablero::Tablero() {
    cant = 0;
}

void Tablero::leerFichas(ifstream& arch)
{
    char id[10],trash[10];
    char tipo;
    int fil, col,t;
    while (arch >> id){
        arch >> trash >> fil;
        tipo = trash[0];
        arch.getline(trash,10);
        col = atoi(trash);
        if (tipo == 'A')
            fichas[cant] = new TipoA;
        else if (tipo == 'B')
            fichas[cant] = new TipoB;
        else if (tipo == 'C')
            fichas[cant] = new TipoC;
        fichas[cant]->setId(id);
        fichas[cant]->setColumna(col);
        fichas[cant]->setFila(fil);
        cant++;
    }
}

void Tablero::leerMovimientos(ifstream&arch)
{
    char id[10],trash[10];
    char mov;
    int cant;
    Ficha *f;
    while (arch >> id){
        arch >> trash;
        mov = trash[0];
        arch.getline(trash,10);
        cant = atoi(trash);
        f = buscarFicha(id);
        f->mover(cant, mov);
    }
}
    
Ficha* Tablero::buscarFicha(char* id)
{
    char idTemp[10];
    for (int i = 0; i < cant; i++){
        fichas[i]->getId(idTemp);
        if (strcmp(idTemp,id) == 0) return fichas[i];
    }
    return NULL;
}

void Tablero::impTablero(void)
{
    Ficha* f;
    char id[10];
    for (int i = 0; i < cant; i++){
        f = fichas[i];
        f->getId(id);
        cout << id << '\t' << f->getTipo() << '\t' 
             << f->getFila() << '\t' << f->getColumna() << endl;
    }
}

