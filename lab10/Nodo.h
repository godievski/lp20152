/* 
 * File:   Nodo.h
 * Author: alulab14
 *
 * Created on 27 de noviembre de 2015, 08:01 AM
 */
/*
 NOMBRE: DIEGO ALONSO GUARDIA AYALA
 * COD: 20125849
 */
#ifndef NODO_H
#define	NODO_H

#include <cstdlib>
template <typename TipoDato> class Lista;

template <typename TipoDato>
class Nodo {
    Nodo();
private:
    friend class Lista <TipoDato>;
    TipoDato* dato;
    Nodo<TipoDato> *sgte;
};

template<typename TipoDato>
Nodo<TipoDato>::Nodo()
{
    dato = NULL;
    sgte = NULL;
}

#endif	/* NODO_H */

