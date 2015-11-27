/* 
 * File:   StringGD.h
 * Author: Usuario
 *
 * Created on 11 de noviembre de 2015, 10:06 AM
 */

#ifndef STRINGGD_H
#define	STRINGGD_H

#include <cstdlib>
#include <iostream>

using namespace std;

#define INCREMENT 0.3

class StringGD {
public:
    StringGD ();
    StringGD (char *);
    StringGD (int);
    StringGD (const StringGD& orig);
    virtual ~StringGD ();
    void assign (char*);
    void assign (const StringGD&);
    int length (void) const;
    void operator = (char *);
    StringGD& operator = (const StringGD&);
    void append (char*);
    void append (const StringGD&);
    void swap (StringGD&);
    StringGD operator + (const StringGD&) const;
    int compare (char *) const;
    int compare (const StringGD&) const;
    int operator == (const StringGD&) const;
    int operator < (const StringGD&) const;
    int operator > (const StringGD&) const;
    void print (void) const;
    void char_cast (char *) const; //My own method
    char operator [] (int) const;
private:
    char *str;
    int len;
    int cap;
    int _strlen(char*) const;
    int _min(int, int) const;
};

#endif	/* STRINGGD_H */

