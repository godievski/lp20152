/*
 * NOMBRE: DIEGO ALONSO GUARDIA AYALA
 * CODIGO: 20125849
 * 
 */

#ifndef ALMACENASEMESTRE_H
#define	ALMACENASEMESTRE_H


void* leerCursos (void);

void separaPalabras (char *, char **, int &);

void guardarCurso(void **, int &, int &,
                    char *, double , int);

void aumentarTam(void **, int &, int);

double promedio (void*);

#endif	/* ALMACENASEMESTRE_H */

