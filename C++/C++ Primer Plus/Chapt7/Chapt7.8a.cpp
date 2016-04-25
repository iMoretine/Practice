#include <iostream>  
using namespace std;  

const int seasons = 4; 
const char *season[seasons] = {"Spring","Summer","Fall","Winter"};

int fill(double *expensive)
{
 	for(int i=0;i<seasons;i++)
 	{
 		cout<<"Enter "<<*(season+i)<<" expenses : ";
 		cin>>*(expensive+i);
 	}
 	cout<<"End;"<<endl;
 	return 0;
}

int show(const double *arr)
{
	cout<<"Start : "<<endl;
	for(int i=0;i<seasons;i++)
	{
		cout<<"The "<<*(season+i)<<" expenses is "<<*(arr+i)<<endl;
	}
	cout << "End;"<<endl;
	return 0;
}

int main()  
{
	double expenses[seasons];
	fill(expenses);
	show(expenses);
	return 0;
}  