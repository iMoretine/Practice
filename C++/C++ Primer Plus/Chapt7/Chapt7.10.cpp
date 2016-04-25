#include <iostream>
using namespace std;  

double add(double x,double y)
{
	return x+y;
}

double calculate(double a,double b,double (*pf)(double,double))
{
	return (*pf)(a,b);
}

int main()  
{
	double q = calculate(2.5,10.4,add);
	cout<<q<<endl;
	cout<<"Done."<<endl;
	return 0;
}