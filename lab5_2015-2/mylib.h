/* 
 * File:   mylib.h
 * Nombre: Diego Alonso Guardia Ayala
 * Codigo: 20125849
 * Created on 2 de octubre de 2015, 07:59 AM
 */

#ifndef MYLIB_H
#define	MYLIB_H

void leerCursos (void *&);

void * leeUnCurso (char *&, char*&);

void agregarCurso(void **, int &, char *, char *);

void separaPalabras(char *, char **, int &);

void leeMatricula (void *&);

void aumentarDosElementosCursos(void *);

void * leeAlumno (int &, char *&, char **, int &);

void agregarAlumno (void *, int , char *, 
                    char **, int, int*, int*);

int buscarCurso (void *, char *);

void aumentarTamListas(void *, int, int *, int *);

void listaDeClase (void *);

/*FUNCIONES PARA IMPRIMIR Y MOSTRAR DATOS*/

void impCursos1 (void *);

void printNChar (char, int, int = 1);

#endif	/* MYLIB_H */

