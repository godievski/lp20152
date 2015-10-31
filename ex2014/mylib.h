/* 
 * File:   mylib.h
 * Author: Usuario
 *
 * Created on 6 de octubre de 2015, 10:54 AM
 */

#ifndef MYLIB_H
#define	MYLIB_H

void leerDatos (void *&cursos, void *&alumnos);

void *leeCurso (int &codAlum);

void * leeAlumno(int codAlum);

void agregarNotas(void *alumnos);

char * leePalabra (void);

void agregarListaNota (void *alumnos);

void agregarUnaNota (void *alumnos, char *codCur, int codAlum, int nota);

int buscaAlumno (void *alumnos, int codAlum);

int buscaCurso (char **listaCur, char *codCur);

void aumentarTamLista (void *alumnos, int indAlum);

void separacionDeEgresados (void *cursos, void *&alumnos, void *&egresados);

void leeNombYCredFac(char *&nombFac, double &credFac);

double calcCredAprob (void **reg, void *cursos);

double buscaCredCurso(void *cursos, char *codCurso);

void agregaEgresado(void **buffEgresados, int &cantEgre, void **reg);

void separaPalabras(char *linea,char **palabras, int &cantPal);

void printCursos(void *cursos);

void printAlumnos (void *alumnos);

void printAlumnosConNota (void *alumnos);

void printEgresados(void *egresados);

void printNChar(char c, int n, int ln = 1);

#endif	/* MYLIB_H */

