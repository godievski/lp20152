/* 
 * File:   AdministradorDeArchivos.h
 * Author: alulab14
 *
 * Created on 6 de noviembre de 2015, 08:07 AM
 */

/*
 * Nombre: Diego Alonso Guardia Ayala
 * Codigo: 20125849
 */

#ifndef ADMINISTRADORDEARCHIVOS_H
#define	ADMINISTRADORDEARCHIVOS_H

#include "Alumno.h"
#include <cctype>
#include <fstream>
#include <iostream>
using namespace std;

class AdministradorDeArchivos {
public:
    AdministradorDeArchivos();
    AdministradorDeArchivos(char*);
    void crearArchivo (void);
    void motrarArchivo (void);
    void setNombreTxt(char *);
    void getNombreTxt(char *) const;
    void setNombreBin(char *);
    void getNombreBin(char *) const;
    void setNombres(char *);
private:
    Alumno alum;
    char nombreTxt[50];
    char nombreBin[50];
    void leeNombre(ifstream &, char*);
    void leeEspecialidad(ifstream &,char*);
};

#endif	/* ADMINISTRADORDEARCHIVOS_H */

