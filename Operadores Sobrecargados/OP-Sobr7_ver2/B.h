/* 
 * File:   B.h
 * Author: Miguel Guanira
 *
 * Created on 22 de junio de 2009, 04:03 PM
 */
#include "A.h"

#ifndef _B_H
#define	_B_H
class B    { //la clase B es una agregación
    int b;
    int cant;
    A m[20];
public:
    B(void);
    void setB(int);
    int getB(void);
    int getCant(void);
    void ingresa(int);
    int operator[](int);
    int operator () (int, int);
 };
#endif	/* _B_H */

