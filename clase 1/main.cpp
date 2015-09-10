/* %d -> int
 * %f -> float
 * %lf -> double
 * %c -> char
 * %p -> dirección de memoria
 */


#include <iostream>
#include <iomanip>
using namespace std;
//#include <cstdio>
//#include <cstdlib>

int main ()
{
	int x=12,y=542,z=76;
	cout.width(6);
	cout<<x;
	cout.width(6);
	cout<<y;
	cout.width(6);
	cout<<z<<endl;
	cout<<right<<setw(6)<<x<<setw(6)<<y<<setw(6)<<z<<endl;
	cout<<left<<setw(6)<<x<<setw(6)<<y<<setw(6)<<z<<endl;


	double r = 23412.42134234122, s = 0.000342234;

	cout.precision(5);
	cout<<fixed; //sin esto lo anterior solo cuenta la cantidad de caracteres a imprimir
	cout<<"R = "<<r<<endl;
	cout<<"S = "<<s<<endl;
	
}
