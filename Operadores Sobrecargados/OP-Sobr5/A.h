/* 
 * File:   A.h
 * Author: Miguel Guanira
 *
 * Created on 19 de junio de 2009, 10:16 PM
 */

#ifndef _A_H
#define	_A_H
class A{
    float x;
public:
    A(float cx=0);
    void setX(float);
    float getX(void);
    A operator ++ (void);// como prefijo
    A operator ++ (int); // como sufijo el parámetro int es obligatorio
};
#endif	/* _A_H */

