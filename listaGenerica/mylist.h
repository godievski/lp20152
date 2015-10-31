/* 
 * File:   mylist.h
 * Author: Usuario
 *
 * Created on 6 de octubre de 2015, 09:21 AM
 */

#ifndef MYLIST_H
#define	MYLIST_H

void creaLista (void*&,              //puntero a la pila
                void* (*) (void),    //funcion de lectura
                int (*) (const void*, const void*)); //funcion de comparacion

void imprimeLista (void *,          //puntero a la lista
                   void (*)(void *));  //funcion de impresion

void eliminaLista (void*,   //puntero a la lista
                   void (*) (void*)); //funcion de elimina



#endif	/* MYLIST_H */

