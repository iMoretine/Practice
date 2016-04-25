#include <iostream>
using namespace std;

int main()
{
	double sum = 0;
	double input;
	cout << "Enter a number , 0 for end "<<endl;
	cin >> input;
	while(input)
	{
		sum += input;
		cout<<"now sum is "<<sum<<endl;
		cout<<" Enter another number : ";
		cin>>input;
	}
	return 0;
}