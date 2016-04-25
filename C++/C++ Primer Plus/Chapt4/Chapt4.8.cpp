#include <iostream>
#include <string>

using namespace std;

struct Pizza
{
	string coporation;
	double diameter;
	double weight;
};

int main()
{
	Pizza *pizza;
	pizza = new Pizza();

	cout << "Enter the company name : ";
	getline(cin,pizza->coporation);
	cout << "Enter the weight : ";
	cin >> pizza->weight;
	cout << "Enter the diameter : ";
	cin >> pizza->diameter;

	cout << "Coporation: "<<pizza->coporation<<endl;
	cout << "Weight: "<<pizza->weight<<endl;
	cout << "diameter: "<<pizza->diameter<<endl;
	
	delete pizza;
	return 0;
}
