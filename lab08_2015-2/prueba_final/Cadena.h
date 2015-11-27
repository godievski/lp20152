/* 
 * File:   Cadena.h
 * Author: alulab14
 *
 * Created on 13 de noviembre de 2015, 07:57 AM
 */

/*
 * Nombres: DIEGO ALONSO GUARDIA AYALA
 * Codigo: 20125849
 */

#ifndef CADENA_H
#define	CADENA_H

#include <cstdlib>
#include <iostream>
using namespace std;

#define INCREMENTO 0.3


class Cadena {
public:
    Cadena();
    Cadena(char *);
    Cadena(int);
    Cadena(const Cadena& orig);
    virtual ~Cadena();
    int length (void) const;
    void assign (char*);
    void assign (const Cadena &);
    Cadena operator = (char *);
    Cadena operator = (const Cadena&);
    void append (char*);
    void append (const Cadena&);
    void swap (Cadena &);
    Cadena operator + (const Cadena&);
    int compare (char *) const;
    int compare (const Cadena&) const;
    int operator == (const Cadena &) const;
    int operator < (const Cadena &) const;
    int operator > (const Cadena &) const;
    void print (void) const;
private:
    char *str;
    int len;
    int cap;
    int _strlen(char *) const;
    int _min(int, int) const;
};

#endif	/* CADENA_H */

