/* 
 * File:   Base.h
 * Author: Usuario
 *
 * Created on 17 de noviembre de 2015, 08:17 AM
 */

#ifndef BASE_H
#define	BASE_H


#include <iostream>
using namespace std;

class Base {
public:
    void SetAt1(int at1);
    int GetAt1() const;
    virtual void leerDatos(void);
    virtual void mostrarDatos(void);
private:
    int at1;
};

#endif	/* BASE_H */

