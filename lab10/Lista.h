/* 
 * File:   Lista.h
 * Author: alulab14
 *
 * Created on 27 de noviembre de 2015, 08:00 AM
 */

/*
 NOMBRE: DIEGO ALONSO GUARDIA AYALA
 * COD: 20125849
 */

#ifndef LISTA_H
#define	LISTA_H

#include "Nodo.h"
#include <cstdlib>

template <typename TipoDato>
class Lista {
public:
    Lista();
    void insertar (TipoDato dato);
    int obtener (int, TipoDato* &dato);
    int buscar (TipoDato dato);
    int length (void);
private:
    class Nodo <TipoDato> *inicio;
    int tam;
};

template <typename TipoDato>
Lista<TipoDato>::Lista() {
    inicio = NULL;
    tam = 0;
}


template <typename TipoDato>
int Lista<TipoDato>::length (void)
{
    return tam;
}

template <typename TipoDato>
void Lista<TipoDato>::insertar (TipoDato dato)
{
    Nodo <TipoDato> *nuevoNodo = new Nodo<TipoDato>;
    nuevoNodo->dato = dato;
    Nodo<TipoDato> *ant = NULL; //nodo anterior
    Nodo<TipoDato> *act = inicio; //nodo actual
    while (act != NULL){
        if (act->dato > dato)
            break;
        ant = act;
        act = act->sgte;
    }
    if (ant != NULL)
        ant->sgte = nuevoNodo;
    else
        inicio = nuevoNodo;
    nuevoNodo->sgte = act;  
    tam++;
}

template <typename TipoDato>
int Lista<TipoDato>::obtener (int i, TipoDato* &dato)
{
    int ind = 0;
    Nodo<TipoDato> *act = inicio; //nodo actual
    while (act != NULL){
        if (ind == i){
            dato = &(act->dato);
            return 1;
        }
        ind++;
        act = act->sgte;
    }
    return 0;
}

template <typename TipoDato>
int  Lista<TipoDato>::buscar (TipoDato dato)
{
    int ind = 0;
    Nodo<TipoDato> *act = inicio; //nodo actual
    while (act != NULL){
        if (act->dato == dato)
            return ind;
        ind++;
        act = act->sgte;
    }
    return -1;
}

#endif	/* LISTA_H */

