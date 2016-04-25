#include <iostream>
using namespace std;

struct Car
{
	char make[20];
	int yearMade;
};

int main()
{
	int carNum;
	cout << "How many cars do you wish to catalog ? ";
	cin >> carNum;
	cin.get();
	Car *car = new Car[carNum];
	Car *p = car;

	for(int i=0;i<carNum;i++)
	{
		cout<<"Car #"<<i+1<<":"<<endl;
		cout<<"Please enter the make : ";
		cin.getline(p->make,20);
		cout<<"Please enter the year made : ";
		cin>>p->yearMade;
		cin.get();
		p++;
	}

	p = car;
	cout << "Here is your collection : "<<endl;
	for(int i=0;i<carNum;i++)
	{
		cout<<p->yearMade<<" "<<car[i].make<<endl;
	}
	delete [] car;
	return 0;
}