/* 
 * File:   reporte.h
 * Author: Usuario
 *
 * Created on 7 de octubre de 2015, 10:45 PM
 */

#ifndef REPORTE_H
#define	REPORTE_H

void reporteFinal (void *autores, void *libros);

void ordenarAutores(void *autores, int (*comparaCodInt) (const void*, const void*));

int comparaRegXCod(const void*, const void*);

void ordenarListaLibros(void *autores, int (*comparaCodStr) (const void*, const void*));

int comparaCodStr(const void*, const void*);

void impListaLib(char **listaLib, void *libros);

void buscaNombYPrec (void *libros, char *codLib, char *&nombLib, double *&precLib);

#endif	/* REPORTE_H */

