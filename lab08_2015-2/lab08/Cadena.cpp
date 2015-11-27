/* 
 * File:   Cadena.cpp
 * Author: alulab14
 * 
 * Created on 13 de noviembre de 2015, 07:57 AM
 */


/*
 * Nombres: DIEGO ALONSO GUARDIA AYALA
 * Codigo: 20125849
 */


#include "Cadena.h"

Cadena::Cadena() {
    this->len = 0;
    this->cap = 0;
    this->str = NULL;
}

Cadena::Cadena(char *strX) {
    if (!strX){
        cerr << "Error: Parametro nulo.\n";
        exit(1);
    }
    int len_strX = _strlen(strX);
    this->len = len_strX;
    this->cap = len_strX;
    this->str = new char[this->cap];
    for (int i = 0; i < this->len; i++)
        this->str[i] = strX[i];
}

Cadena::Cadena(int c) {
    this->len = 0;
    this->cap = c;
    this->str = new char[this->cap];
}

Cadena::Cadena(const Cadena& orig) {
    this->len = orig.length();
    this->cap = orig.cap;
    this->str = new char[this->cap];
    for (int i = 0; i < this->len; i++)
        this->str[i] = orig.str[i];
}

Cadena::~Cadena() {
    delete [] this->str;
}

int Cadena::length (void) const
{
    return this->len;
}

void Cadena::assign (char*strX)
{
    if (!strX){
        cerr << "Error: Parametro nulo.\n";
        exit(1);
    }
    int len_strX = _strlen(strX);
    if (this->cap < len_strX){
        this->cap = (1 + INCREMENTO) * len_strX;
        delete [] this->str;
        this->str = new char[this->cap];
    }
    for (int i = 0; i < len_strX; i++)
        this->str[i] = strX[i];
    this->len = len_strX;
}

void Cadena::assign (const Cadena &strX)
{
    int len_strX = strX.length();
    if (this->cap < len_strX){
        this->cap = (1 + INCREMENTO) * len_strX;
        delete [] this->str;
        this->str = new char[this->cap];
    }
    for (int i = 0; i < len_strX; i++)
        this->str[i] = strX.str[i];
    this->len = len_strX;
}

Cadena Cadena::operator = (char *strX)
{
    if (!strX){
        cerr << "Error: Parametro nulo.\n";
        exit(1);
    }
    assign(strX);
    return *this;
}
Cadena Cadena::operator = (const Cadena& strX)
{
    assign(strX);
    return *this;
}

void Cadena::append (char*strX)
{
    if (!strX){
        cerr << "Error: Parametro nulo.\n";
        exit(1);
    }
    int len_strX = _strlen(strX);
    int lim = len_strX + this->len;
    Cadena temp (this->cap);
    if (this->cap < lim){
        temp.assign(*this);
        this->cap = (1 + INCREMENTO) * (lim);
        delete [] this->str;
        this->str = new char[this->cap];
        assign(temp);
    }
    for (int i = 0; i < len_strX; i++)
        this->str[this->len + i] = strX[i];
    this->len += len_strX;
}

void Cadena::append (const Cadena& strX)
{
    int len_strX = strX.length();
    int lim = len_strX + this->len;
    Cadena temp (this->cap);
    if (this->cap < lim){
        temp.assign(*this);
        this->cap = (1 + INCREMENTO) * (lim);
        delete [] this->str;
        this->str = new char[this->cap];
        assign(temp);
    }
    for (int i = 0; i < len_strX; i++)
        this->str[this->len + i] = strX.str[i];
    this->len += len_strX;
}

void Cadena::swap (Cadena &strX)
{
    Cadena temp;
    temp.assign(*this);
    assign(strX);
    strX.assign(temp);
}

Cadena Cadena::operator + (const Cadena &strX)
{
    Cadena temp = *this;
    temp.append(strX);
    return Cadena (temp);
}

int Cadena::compare (char *strX) const
{
    int len_str = _strlen(strX);
    int len_min = _min(len_str, this->len);
    
    for (int i = 0; i < len_min; i++){
        if (this->str[i] < strX[i])
            return -1;
        else if (this->str[i] > strX[i])
            return 1;
    }
    
    if (len_str == this->len)
        return 0;
    else if (len_str == len_min)
        return 1;
    else
        return -1;
}

int Cadena::compare (const Cadena& strX) const
{
    int len_str = strX.length();
    int len_min = _min(len_str, this->len);
    
    for (int i = 0; i < len_min; i++){
        if (this->str[i] < strX.str[i])
            return -1;
        else if (this->str[i] > strX.str[i])
            return 1;
    }
    
    if (len_str == this->len)
        return 0;
    else if (len_str == len_min)
        return 1;
    else
        return -1;
}

int Cadena::operator == (const Cadena &strX) const
{
    return compare(strX) == 0;
}
int Cadena::operator < (const Cadena &strX) const
{
    return compare(strX) < 0;
}
int Cadena::operator > (const Cadena &strX) const
{
    return compare(strX) > 0;
}

void Cadena::print (void) const
{
    for (int i = 0; i < this->len; i++)
        cout << this->str[i];
}

int Cadena::_strlen(char *str) const
{
    if (!str){
        cerr << "Error: Parametro nulo.\n";
        exit(1);
    }
    int len = 0;
    for (len = 0; str[len]; len++);
    return len;
}

int Cadena::_min(int a, int b) const
{
    if (a < b)
        return a;
    else
        return b;
}


