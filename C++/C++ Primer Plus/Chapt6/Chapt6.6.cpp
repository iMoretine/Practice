#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct donation
{
	string name;
	double sum;
};

int main()
{
	cout << "Please enter the number of people:";
	int number;
	cin >> number;
	donation *donate = new donation[number];
	donation *p = donate;

	for(int i=0;i<number;i++)
	{
		cout<<"Enter the "<<i+1<<" donator's name : ";
		cin >> p->name;
		cout<<"Enter the sum of money : ";
		cin >> p->sum;
		p++;
	}

	cout<<"Grand Patrons : "<<endl; 
	p = donate;
	for(int i=0;i<number;i++)
	{
		if(p->sum >= 10000)
			cout << p->name << " "<< p->sum<<endl;
		p++;
	}

	cout<<"Patrons : "<<endl; 
	p = donate;
	for(int i=0;i<number;i++)
	{
		if(p->sum < 10000)
			cout << p->name << " "<< p->sum<<endl;
		p++;
	}

	return 0;
}