#include <iostream>
#include <cctype>
#include <array>

const int MAX = 10;
using namespace std;

int main()
{
	array<double,MAX> donation = {0};
	char str[20];

	double avg;
	double sum = 0;
	cout<<"Enter the number : "<<endl;
	for(int i=0;i<MAX;i++)
	{
		cin>>donation[i];
		sum += donation[i];
	}

	avg = sum / MAX;

	for(int i=0;i<MAX;i++)
	{
		if(donation[i] > avg)
		{
			cout << donation[i] << " ";
		}
		cout<<endl;
	}
	cout << avg <<endl;
	return 0;
}