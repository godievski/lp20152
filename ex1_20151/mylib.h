/* 
 * File:   mylib.h
 * Author: Usuario
 *
 * Created on 29 de septiembre de 2015, 08:23 AM
 */

#ifndef MYLIB_H
#define	MYLIB_H

void leeDatos (void *&);

void * leeVenta(int *&, char *&, char*&, int &);

void agregar (int *, char *, char *, int,
              void *[], int &, char**[],
              int *[], int [], int []);

int buscarVendedor (int *, void *[], int);

void *crearReg (int *, char *);

void agregarVenta (int ind, char *codA, int cant, char **codArt[],
                   int *acumulado[], int tam[], int numD[]);

void aumentarEspacios( char **&, int *&, int &, int &);

void separaPalabras(char *, char**,int &);

void reporteDeVentas (void *);

void impVendedor (void *);

#endif	/* MYLIB_H */

