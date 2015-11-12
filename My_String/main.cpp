/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 11 de noviembre de 2015, 10:04 AM
 */

#include <cstdlib>
#include "StringGD.h"
#include <fstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    StringGD p1 ("Hello world!");
    p1.print();
    cout << "\nTest constructor 1 fine!\n";
    
    StringGD p2 (5);
    p2.assign("I am a machine!");
    p2.print();
    cout << "\nTest constructor 2 fine!\n";
    
    StringGD p3 = p2;
    p3.print();
    cout << "\nTest constructor 3 fine!\n";
    
    StringGD p4;
    p4.assign(p1);
    p4.print();
    cout << "\nTest constructor 4 fine!\n";
    
    StringGD p5,p6,p7;
    p5 = "Testing assignment operator!";
    p5.print();
    cout << "\nTest fine!\n";
    
    p6 = p5;
    p6.print();
    cout << "\nTest 2 fine!\n";
    
    
    p7 = p1 = p4;
    p1.print();
    cout << endl;
    p7.print();
    cout << "\nTest 3 fine!\n";
    
    StringGD p8,p9,p10;
    p8 = "Word 1";
    p9 = "Word 2";
    p8.append(" Added!");
    p8.print();
    cout << "\nTest append 1 fine!\n";
    p10 = "-  Added!";
    p9.append(p10);
    p9.print();
    cout << "\nTest append 2 fine!\n";
    
    StringGD p11, p12;
    p11 = "Word 11";
    p12 = "Word 12";
    cout << "p11: ";
    p11.print();
    cout << "\np12: ";
    p12.print();
    p11.swap(p12);
    cout << "\np11: ";
    p11.print();
    cout << "\np12: ";
    p12.print();
    cout << "\nTest swap fine!" << endl;
    
    StringGD p13,p14,p15;
    p13 = "3";
    p14 = " + 1";
    p15 = p13 + p14 + p14;
    p15.print();
    cout << "\nPlus operator fine!\n";
    
    StringGD p16, p17;
    p16 = "Diego";
    p17 = "Diego";
    cout << "Comparing: ";
    p16.print();
    cout << " vs ";
    p17.print();
    cout << "\nSolution with char[]: ";
    cout << p16.compare("Diego");
    cout << "\nSolution with StringGD object p17: ";
    cout << p16.compare(p17);
    cout << "\nSolution with StringGD object p16: ";
    cout << p17.compare(p16) << endl;
    
    cout << "Comparing: ";
    p17 = "Alonso";
    p16.print();
    cout << " < ";
    p17.print();
    cout << " ? : ";
    cout << (p16 < p17) << endl;
    p16.print();
    cout << " > ";
    p17.print();
    cout << " ? : ";
    cout << (p16 > p17) << endl;
    p16.print();
    cout << " == ";
    p17.print();
    cout << " ? : ";
    cout << (p16 == p17) << endl;
    return 0;
}

