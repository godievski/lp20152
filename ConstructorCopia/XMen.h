/* 
 * File:   XMen.h
 * Author: Usuario
 *
 * Created on 4 de noviembre de 2015, 08:26 AM
 */

#ifndef XMEN_H
#define	XMEN_H

class XMen {
public:
    XMen();
    /*CONSTRUCTOR COPIA*/
    XMen(const XMen& orig);
    virtual ~XMen();
    void SetMp(double mp);
    double GetMp() const;
    void SetHp(double hp);
    double GetHp() const;
    void SetNombre(char* nombre);
    char* GetNombre(char *nombre) const;
    void operator + (double);
private:
    double hp;
    double mp;
    char *nombre;
};

#endif	/* XMEN_H */

