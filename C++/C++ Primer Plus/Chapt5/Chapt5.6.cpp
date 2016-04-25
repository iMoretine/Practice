#include <iostream>
using namespace std;

int main()
{
	char month[12][20] = {"January","Februry","March","April","May","June","July","August","September","October","November","December"};
	int num[3][12];
	int sum[3] = {0};

	for(int i = 0;i<3;i++)
	for(int j = 0;j<12;j++)
	{
		cout<<"The sales volume of "<<month[j]<<" in year "<<i+1<<" is ";
		cin>>num[i][j];
		sum[i]+=num[i][j];
	}
	cout<<"The sales volume in year 1 is "<<sum[0]<<endl;
	cout<<"The sales volume in year 2 is "<<sum[1]<<endl;
	cout<<"The sales volume in year 3 is "<<sum[2]<<endl;
	cout<<"The sales volume of three years  is "<<sum[0]+sum[1]+sum[2]<<endl;
	return 0;
}