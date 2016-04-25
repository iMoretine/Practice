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
	CandyBar snack[3] = {{"Mocha Munch",2.3,350},{"Mocha Munch2",2.5,300},{"Mocha Munch3",2.3,120}};
	for(int i=0;i<3;i++)
	{
		cout << "Brand : "<<snack[i].brand<<endl;
		cout << "Weight : "<<snack[i].weight<<endl;
		cout << "Calorie : "<<snack[i].calorie<<endl;
	}
	return 0;
}
