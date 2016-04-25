#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string name;
	string dessert;
	cout <<"Enter your name:"<<endl;
	getline(cin,name);
	cout<<"Enter your favorate dessert:"<<endl;
	getline(cin,dessert);

	cout<<"I have some delicious "<<dessert;
	cout<<" for you , "<<name <<endl;
	return 0;
}