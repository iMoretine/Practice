#include <iostream>
#include <string>

using namespace std;
struct CandyBar
{
	string brand;
	double weight;
	int calorie;
};

int main()
{
	CandyBar *snack = new CandyBar[3];
	CandyBar *p = snack;
	p->brand =  "Mocha Munch";
	p->weight = 2.3;
	p->calorie = 350;

	cout << "Brand : "<<p->brand<<endl;
	cout << "Weight : "<<p->weight<<endl;
	cout << "Calorie : "<<p->calorie<<endl;
	
	p++;
	p->brand =  "Mocha Munch2";
	p->weight = 1.5;
	p->calorie = 300;
		
	cout << "Brand : "<<p->brand<<endl;
	cout << "Weight : "<<p->weight<<endl;
	cout << "Calorie : "<<p->calorie<<endl;

	p++;
	p->brand =  "Mocha Munch3";
	p->weight = 4.3;
	p->calorie = 210;

	cout << "Brand : "<<p->brand<<endl;
	cout << "Weight : "<<p->weight<<endl;
	cout << "Calorie : "<<p->calorie<<endl;

	delete []snack;
	return 0;
}
