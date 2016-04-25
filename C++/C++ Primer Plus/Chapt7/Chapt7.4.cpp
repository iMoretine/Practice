#include <iostream>
using namespace std;

long double probability(double total ,double choices, double totalSpecials)
{
	long double result =1.0;
	long double n;
	long double p;

	for(n = total,p = choices ; p>0 ; n--,p--)
	{
		result = result * n / p;
	}
	result /=totalSpecials;
	return result;
}

int main()
{
	double total , choices, totalSpecials;
	cout << "Enter the total number of choices on the game card ,\n"
		"the number of picks allowed and the total number of special choices: \n";
	cin >> total >> choices >> totalSpecials;
	while(choices <= total)
	{
		cout << "You have one chance in ";
		cout << probability(total,choices,totalSpecials);
		cout << " of win.\n";
		cout << "Next three numbers (q to quit): ";
		cin >> total >> choices >> totalSpecials;
	}
	cout << "bye\n";
	
	return 0;
}