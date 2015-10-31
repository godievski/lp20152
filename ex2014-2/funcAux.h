/* 
 * File:   funcAux.h
 * Author: Usuario
 *
 * Created on 7 de octubre de 2015, 11:16 PM
 */

#ifndef FUNCAUX_H
#define	FUNCAUX_H

void separaPalabras (char *buffer, char **palabras, int &cantPal);

void printNChar (char c, int n, int ln = 1);

void myQSort (void **array, int n, int (*funcCmp) (const void*, const void*));

void swap (void **array, int i, int j);
#endif	/* FUNCAUX_H */

