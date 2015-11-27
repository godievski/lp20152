/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 24 de noviembre de 2015, 09:17 AM
 */

#include <list>
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
    list <string> l;
    string s;
    while (cin >>s)
        l.push_back(s);
    s = "hugo";
    l.push_front(s);
    l.sort();
    for (list<string>::iterator it = l.begin(); it != l.end(); it++)
        cout << *it << endl;
    return 0;
}

