/* 
 * File:   Persona.h
 * Author: Usuario
 *
 * Created on 3 de noviembre de 2015, 08:31 AM
 */

#ifndef PERSONA_H
#define	PERSONA_H

class Persona {
public:
    void SetSueldo(double sueldo);
    double GetSueldo() const;
    void SetNombre(char* nombre);
    void GetNombre(char *nombre) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void imprime(void) const;
private:
    int codigo;
    char nombre[40];
    double sueldo;
};

#endif	/* PERSONA_H */

