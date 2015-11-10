/* 
 * File:   Persona.h
 * Autor:  J. Miguel Guanira E.
 *
 * Created on 15 de noviembre de 2010, 07:13 PM
 */

#ifndef PERSONA_H
#define	PERSONA_H
#include <ostream>
using namespace std;

class Persona{
    int dni;
    char *nombre;
    float sueldo;
public:
    void leerDatos(void);
    void imprimeDatos(void);
    friend istream & operator >>(istream &, Persona &);
    friend ostream & operator <<(ostream &, Persona &);
};



#endif	/* PERSONA_H */

