#include <iostream>

int main()
{
	using namespace std;
	long long populationOfWorld;
	long long populationOfUS;
	cout << "Enter the  world's population: ";
	cin >> populationOfWorld;
	cout << "Enter the population of the US: ";
	cin >> populationOfUS;
	cout << "The population of the US is " << (double)populationOfUS/(double)populationOfWorld*100 << "% of the world population.\n";

	return 0;
}