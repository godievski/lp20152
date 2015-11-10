/* 
 * File:   Cilindro.h
 * Author: Usuario
 *
 * Created on 10 de noviembre de 2015, 09:21 AM
 */

#ifndef CILINDRO_H
#define	CILINDRO_H

#include "Circulo.h"

class Cilindro: public Circulo {
public:
    Cilindro();
    Cilindro(const Cilindro& orig);
    virtual ~Cilindro();
    double volumen (void);
    double area (void);
    void setAltura(double altura);
    double getAltura() const;
    void imprime(void);
private:
    double altura;
};

#endif	/* CILINDRO_H */

