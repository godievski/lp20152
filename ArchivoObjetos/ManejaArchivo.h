/* 
 * File:   ManejaArchivo.h
 * Author: Usuario
 *
 * Created on 3 de noviembre de 2015, 08:50 AM
 */

#ifndef MANEJAARCHIVO_H
#define	MANEJAARCHIVO_H

#include "Persona.h"


class ManejaArchivo {
public:
    ManejaArchivo();
    ManejaArchivo(char*);
    ManejaArchivo(char*, char c);
    virtual ~ManejaArchivo();
    void crearArchivo (void);
    void mostrarArch (void);
    void incrementarSueldo (double);
private:
    char* nombreArch;
    class Persona per;
};

#endif	/* MANEJAARCHIVO_H */

