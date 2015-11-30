/* 
 * File:   TipoA.cpp
 * Author: Usuario
 * 
 * Created on 28 de noviembre de 2015, 10:04 PM
 */

#include "TipoA.h"

TipoA::TipoA() {
    this->setTipo('A');
}

void TipoA::mover(int cant, char t)
{
    if (cant <= 0) return;
    if (t == 'P')
        this->setFila(this->getFila() + cant);
    else if(t == 'R')
        this->setFila(this->getFila() - cant);
    else if (t == 'S')
        this->setColumna(this->getColumna() - cant);
    else if (t == 'Q')
        this->setColumna(this->getColumna() + cant);
}
