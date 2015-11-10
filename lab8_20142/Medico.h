/* 
 * File:   Medico.h
 * Author: Usuario
 *
 * Created on 5 de noviembre de 2015, 03:21 PM
 */

#ifndef MEDICO_H
#define	MEDICO_H

#include <cstring>
#include <iostream>

using namespace std;
#define MAX_NOMBRE 21

class Medico {
public:
    Medico(int cod);
    void SetSueldo(double sueldo);
    double GetSueldo() const;
    void SetEspecialidad(char*);
    void GetEspecialidad(char*) const;
    void SetApellido(char *);
    void GetApellido(char *) const;
    void SetNombre(char *);
    void GetNombre(char *) const;
    int GetCodigo() const;
    void imprime (void) const;
private:
    int codigo;
    char nombre[MAX_NOMBRE];
    char apellido[MAX_NOMBRE];
    char especialidad[MAX_NOMBRE];
    double sueldo;
};

#endif	/* MEDICO_H */

