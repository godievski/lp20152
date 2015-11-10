/* 
 * File:   XMen.cpp
 * Author: Usuario
 * 
 * Created on 4 de noviembre de 2015, 08:26 AM
 */

#include "XMen.h"
#include <cstdlib>
#include <cstring>


XMen::XMen() {
    nombre = NULL;
}
/* CONSTRUCTOR COPIA*/
XMen::XMen(const XMen& orig) {
    hp = orig.hp;
    mp = orig.mp;
    SetNombre(orig.nombre);
}

XMen::~XMen() {
    delete nombre;
}

void XMen::SetMp(double mp) {
    this->mp = mp;
}

double XMen::GetMp() const {
    return mp;
}

void XMen::SetHp(double hp) {
    this->hp = hp;
}

double XMen::GetHp() const {
    return hp;
}

void XMen::SetNombre(char* nombre) {
    strcpy(this->nombre, nombre);
}

char* XMen::GetNombre(char* nombre) const {
    strcpy(nombre, this->nombre);
    return nombre;
}

void XMen::operator +(double x){
    hp *= x;
}