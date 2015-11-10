/* 
 * File:   Quebrado.h
 * Author: Miguel Guanira
 *
 * Created on 21 de junio de 2009, 10:07 PM
 */

#ifndef _QUEBRADO_H
#define	_QUEBRADO_H
class Quebrado{
    int numerador;
    int denominador;
public:
    Quebrado(int = 0, int = 1);
    void setNum(int);
    void setDen(int);
    int getNum(void);
    int getDen(void);
    void muestra(void);
    Quebrado simplifica(void);
    Quebrado operator = (Quebrado);
    Quebrado operator += (Quebrado);
    Quebrado operator -= (Quebrado);
    friend Quebrado operator + (Quebrado, Quebrado);
    friend Quebrado operator - (Quebrado, Quebrado);
    operator float();
 };
#endif	/* _QUEBRADO_H */

