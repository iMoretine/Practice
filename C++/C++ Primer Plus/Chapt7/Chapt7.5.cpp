#include <iostream>
using namespace std;

long factorial(int n)
{
	if(n==0)
		return 1;
	else
		return n = n*factorial(n-1);
}

int main()
{
	cout<<"Enter the number : \n";
	int n ;

	while(cin>>n)
	{
		long result = factorial(n);
		cout << "Result : "<<n<<"! = "<<result<<endl;
		cout<<"Enter the number : \n";
	}
	return 0;
}