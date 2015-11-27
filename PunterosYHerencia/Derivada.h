/* 
 * File:   Derivada.h
 * Author: Usuario
 *
 * Created on 17 de noviembre de 2015, 08:20 AM
 */

#ifndef DERIVADA_H
#define	DERIVADA_H

#include "Base.h"

class Derivada: public Base {
public:
    void SetAt2(int at2);
    int GetAt2() const;
    void leerDatos(void);
    void mostrarDatos(void);
private:
    int at2;
};

#endif	/* DERIVADA_H */

