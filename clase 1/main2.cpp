#include <iostream>
#include <iomanip>
using namespace std;
#include <cstdio>
#include <cstdlib>

int main ()
{
	int a, s= 0;

	/*Version1
	while (scanf("%d",&a) != EOF)
		s += a;
	printf("a = %d \ns = %d\n",a,s);
	*/

	/* Version2
	while (cin>>a)
		s+=a;
	cout<<"a = "<<a<<endl<<"S= "<<s<<endl;
	*/
	
	//Version3
	cin>>a;	
	while (!cin.eof()){
		s+=a;
		cin>>a;
	}
	cout<<"a = "<<a<<endl<<"S= "<<s<<endl;
	return 0;
}
