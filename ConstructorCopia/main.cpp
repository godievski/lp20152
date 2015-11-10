/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 4 de noviembre de 2015, 08:25 AM
 */

#include <cstdlib>
#include <cstdio>
#include "XMen.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    XMen wolverine;
    wolverine.SetHp(100.24);
    wolverine.SetMp(1202.2);
    //wolverine.SetNombre("X-Men");
    
    
    
    printf("HP: %lf\n",wolverine.GetHp());
    wolverine + 2;
    printf("HP: %lf\n",wolverine.GetHp());
    //printf("HP: %lf\n",wolverine.GetHp());
    
    
    return 0;
}

