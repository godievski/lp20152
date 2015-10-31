/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 20 de octubre de 2015, 08:15 AM
 */

#include <cstdlib>
#include <cstdio>

/*
 * 
 */
int main(int argc, char** argv) {

    for (int i = 0; i < argc; i++){
        printf("%02d) %s\n",i+1, argv[i]);
    }
    
    return 0;
}

