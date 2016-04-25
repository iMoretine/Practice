#include <iostream>
#include <array>

using namespace std;

int main()
{
	array<int,3> arr;
	double sum = 0;
	double average;
	for(int i=0;i<3;i++)
	{
		cout<<"Enter the grade(time "<<i+1<<") :";
		cin>>arr[i];
		sum +=arr[i];
	}
	average = sum/3;
	cout<<"The average grade is "<<average<<endl;
	return 0;
}