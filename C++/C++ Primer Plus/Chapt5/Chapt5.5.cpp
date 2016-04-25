#include <iostream>
using namespace std;

int main()
{
	char month[12][20] = {"January","Februry","March","April","May","June","July","August","September","October","November","December"};
	int num[12];
	int sum = 0;
	for(int i=i;i<12;i++)
	{
		cout<<"The sales volume of "<<month[i]<<" is ";
		cin>>num[i];
		sum+=num[i];
	}
	cout<<"The sales volume of the year is "<<sum<<endl;
	return 0;
}