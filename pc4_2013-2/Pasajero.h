/* 
 * File:   Pasajero.h
 * Author: Usuario
 *
 * Created on 19 de noviembre de 2015, 03:57 PM
 */

#ifndef PASAJERO_H
#define	PASAJERO_H

class Pasajero {
public:
    Pasajero();
    virtual ~Pasajero();
    void SetDni(int dni);
    int GetDni() const;
    void SetDestino(char* destino);
    void GetDestino(char*) const;
    void SetNombre(char* nombre);
    void GetNombre(char*) const;
private:
    char *nombre;
    char *destino;
    int dni;
};

#endif	/* PASAJERO_H */

