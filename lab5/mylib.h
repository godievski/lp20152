/* 
 * File:   mylib.h
 * Author: Usuario
 *
 * Created on 29 de septiembre de 2015, 02:14 PM
 */

#ifndef MYLIB_H
#define	MYLIB_H

void leeDatos (void *&, void *&);

void * leeMedico (char *&,double *&);

void agregarMedico (void *&, char *, double *, int &, int &);

void * leeConsulta (void *&, char *&);

void agregaPacYActualizaDatos (void *&, void *, void *, char *,int &, int &);

void aumentarTam (void *&, int &, int);

void separarPalabras (char *, char **, int &);

void impInforme (void *, void *);


#endif	/* MYLIB_H */

