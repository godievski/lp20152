/* 
 * File:   libAutores.h
 * Author: Usuario
 *
 * Created on 7 de octubre de 2015, 10:44 PM
 */

#ifndef LIBAUTORES_H
#define	LIBAUTORES_H

void leerAutores (void *&autores);

char* leerNombre (void);

void separaPalabras (char *buffer, char **palabras, int &cantPal);

void guardarDatos (void **buffer, int &cantAut, int codigo, char *nombre);

void printAut (void *autores);
#endif	/* LIBAUTORES_H */

