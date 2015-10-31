/* 
 * File:   ClaseRect.h
 * Author: Usuario
 *
 * Created on 27 de octubre de 2015, 09:46 AM
 */

#ifndef CLASERECT_H
#define	CLASERECT_H

class ClaseRect {
public:
    void SetAltura(double altura);
    double GetAltura() const;
    void SetBase(double base);
    double GetBase() const;
    void SetNombre(char* nombre);
    char* GetNombre(char* n) const;
    
private:
    double base;
    double altura;
    char *nombre;
};

#endif	/* CLASERECT_H */

