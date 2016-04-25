#include <iostream>
#include <array>
using namespace std;

const int Arsize = 101;

int main()
{
	array<long double,Arsize> factorials;
	factorials[1] = factorials[0] = 1;
	for(int i=2;i<Arsize;i++)
		factorials[i] = factorials[i-1]*i;
	for(int i=0;i<Arsize;i++)
		cout<<i<<"! = "<<factorials[i]<<endl;
	return 0;
}