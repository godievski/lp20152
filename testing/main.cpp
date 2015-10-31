/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 28 de octubre de 2015, 11:08 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int & max (int& a, int &b)
{
    if (a < b) return b;
    return a;
}

/*
 * 
 */
int main(int argc, char** argv) {

    int a= 5, b = 6;
    
    
    int c = max(a,b);
    cout <<"A: " << a << endl;
    cout <<"B: " << b << endl;
    cout <<"C: " << c << endl;
    
    c = 3;
    cout <<"A: " << a << endl;
    cout <<"B: " << b << endl;
    cout <<"C: " << c << endl;
    
    return 0;
}

