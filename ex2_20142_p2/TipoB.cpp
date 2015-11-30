/* 
 * File:   TipoB.cpp
 * Author: Usuario
 * 
 * Created on 28 de noviembre de 2015, 10:05 PM
 */

#include "TipoB.h"

TipoB::TipoB() {
    this->setTipo('B');
}

void TipoB::mover(int cant, char t)
{
    if (cant <= 0) return;
    
    if (t == 'P'){
        this->setFila(this->getFila() + cant);
        this->setColumna(this->getColumna() - cant);
    }else if(t == 'Q'){
        this->setFila(this->getFila() + cant);
        this->setColumna(this->getColumna() + cant);
    }else if (t == 'S'){
        this->setFila(this->getFila() - cant);
        this->setColumna(this->getColumna() - cant);
    }else if (t == 'R'){
        this->setFila(this->getFila() - cant);
        this->setColumna(this->getColumna() + cant);
    }
}


