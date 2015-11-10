/* 
 * File:   Complejo.h
 * Author: Miguel Guanira
 *
 * Created on 19 de junio de 2009, 09:57 PM
 */

#ifndef _COMPLEJO_H
#define	_COMPLEJO_H
class Complejo{
    float real;
    float imag;
public:
    Complejo(float r=0, float i=0);
    void setReal(float);
    void setImaginario(float);
    float getReal(void);
    float getImaginario(void);
    Complejo operator + (Complejo);
    Complejo operator - (Complejo);
    Complejo operator += (Complejo);
};
#endif	/* _COMPLEJO_H */

