/* 
 * File:   ClaseRect.h
 * Author: Usuario
 *
 * Created on 27 de octubre de 2015, 09:14 AM
 */

#ifndef CLASERECT_H
#define	CLASERECT_H

class ClaseRect {
public:
    //Métodos selectores
    void set_base(double);
    double get_base(void);
    void set_altura(double);
    double get_altura(void);
    void leeDatos(void);
    void imprimeDatos(void);
    double area(void);
    double perimetro(void);
    
private:
    double base;
    double altura;
};

#endif	/* CLASERECT_H */

