#include <iostream>
using namespace std;

double getAvg(double a,double b)
{
	return 2.0 * a * b / (a + b);
}

int main()
{
	double a,b;
	cout << "Enter two numbers (0 for quit):"<<endl;
	cin>>a;
	cin>>b;
	while(a!=0 && b!=0)
	{
		cout<<"The average is "<<getAvg(a,b)<<endl;
		cout << "Enter two numbers :"<<endl;
		cin>>a;
		cin>>b;
	}
	cout << "Exit."<<endl;
	return 0;
}