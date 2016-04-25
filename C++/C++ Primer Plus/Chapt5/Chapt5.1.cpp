#include <iostream>
using namespace std;

int main()
{
	int littlenum;
	int bignum;
	int sum = 0;
	cout << "Enter a number : ";
	cin >> littlenum;
	cout <<"Enter a bigger number : ";
	cin >> bignum;

	for(int i = littlenum; i<=bignum; i++)
	{
		sum += i;
	}
	cout << "The sum between "<<littlenum<<" and "<<bignum << " is "<< sum << endl;
	return 0;
}