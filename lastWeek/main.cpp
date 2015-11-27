/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 24 de noviembre de 2015, 08:15 AM
 */

#include <vector>
#include <iterator>
#include <algorithm>

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    vector <int> v;
    cout << "tama\244o inicial: " << v.size() << endl;
    cout << "capacidad inicial: " << v.capacity() << endl;
    v.push_back(15);
    v.push_back(8);
    v.push_back(3);
    v.push_back(21);
    v.push_back(4);
    cout << "tama\244o inicial: " << v.size() << endl;
    cout << "capacidad inicial: " << v.capacity() << endl;
    cout << "Datos: \n";
    for (int i = 0; i < v.size();i++)
        cout << v[i] << endl;
    
    /*ASI SE DEFINE UN ITERADOR PLANTILLA<TIPO DE DATO>::iterator NOMBRE;*/
    vector <int>::iterator it;
    cout << "Datos con iterador: \n";
    for (it = v.begin(); it != v.end(); it++)
        cout << *it << endl;
    
    sort(v.begin(), v.end());
    cout << "Datos ordenados: \n";
    for (it = v.begin(); it != v.end(); it++)
        cout << *it << endl;
    return 0;
}

