/* 
 * File:   libLibros.h
 * Author: Usuario
 *
 * Created on 7 de octubre de 2015, 10:45 PM
 */

#ifndef LIBLIBROS_H
#define	LIBLIBROS_H

void leerLibros (void *&libros, void *autores);

void * leeLibro (char *&codLib, char *&nombLib, double *&precio, int &codAut);

void guardarEnLibros (void **buffLib, int &cantLib,
                    char *codLib, char *nombLib, double *precio);

void guardarEnAutores (void *autores, int codAut,
                       int *tam, int *cant, char *codLib);

int buscarAutor (void *autores, int codAut);

void aumentarTamListaLib (void *autores, int ind, int *tam, int *cant);

void printLib (void *libros);

#endif	/* LIBLIBROS_H */

