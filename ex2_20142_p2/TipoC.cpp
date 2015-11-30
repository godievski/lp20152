/* 
 * File:   TipoC.cpp
 * Author: Usuario
 * 
 * Created on 28 de noviembre de 2015, 10:05 PM
 */

#include "TipoC.h"

TipoC::TipoC() {
    this->setTipo('C');
}

void TipoC::mover(int cant, char t)
{
    if (t == 'P'){
        setFila(getFila() + 2);
        setColumna(getColumna() + 1);
    }else if(t == 'Q'){
        setFila(getFila() - 1);
        setColumna(getColumna() + 2);
    }else if (t == 'S'){
        setFila(getFila() + 1);
        setColumna(getColumna() - 2);
    }else if (t == 'R'){
        setFila(getFila() - 1);
        setColumna(getColumna() - 2);
    }
}
