/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 30 de septiembre de 2015, 08:17 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;
#include "mystack.h"

/*
 * 
 */
int main(int argc, char** argv) {

    char cad[500], *pila, car;
    bool error;
    
    
    while (cin.getline(cad,500)){
        error = false;
        stack_create(pila);
        for (int i = 0; cad[i] && !error; i++){
            if (cad[i] == '(' || cad[i] == '[')
                stack_push(pila, cad[i]);
            else if (cad[i] == ')' || cad[i] == ']'){
                car = stack_pop(pila);
                if ( car==-1 ||
                    (car == '(' && cad[i] != ')') || 
                    (car == '[' && cad[i] != ']')) {
                    error = true;
                }
            }
        }
        if (error || !stack_isEmpty(pila)) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        
    }
    
    
    return 0;
}

