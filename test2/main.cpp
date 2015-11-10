/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 8 de noviembre de 2015, 01:36 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    fstream archTxt ("test.txt", ios::in);
    
    char trash[30],codStr[30], linea[200];
    int anho,sem,codigo;
    void* fin;
    
    
    archTxt.getline(trash,30,' ');
    while (1){
        archTxt >> anho >> sem;
        cout << "Semestre: " << anho << "-"<< sem << endl;
        while (archTxt.get() != '\n');
        while (1){
            if (fin = archTxt.getline(codStr, 30, ' ')){
                codigo = atoi(codStr);
            }else
                codigo = 0;
            if (codigo == 0) break;
            archTxt.getline(linea,200);
            cout << codigo << " " << linea << endl;
        }
        if (!fin) break;
    }
   
    
    return 0;
}

