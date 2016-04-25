#include <iostream>
using namespace std;

int main()
{
	double daphne = 100;
	double cleo = 100;
	int i = 0;
	while(daphne >= cleo)
	{
		daphne += 10;
		cleo += cleo*0.05;
		i++;
	}
	cout<<"After "<<i<<" years , Cleo is bigger than Daphne."<<endl;
	cout<<"Cleo : "<<cleo<<endl;
	cout<<"Daphne : "<<daphne<<endl;
	return 0;
}