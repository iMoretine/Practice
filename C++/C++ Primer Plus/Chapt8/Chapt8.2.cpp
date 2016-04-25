#include <iostream>
#include <cstring>
using namespace std;

struct CandyBar
{
	char* name;
	float weight;
	int energe;
};

int init(CandyBar &CB , char* name , float weight,int energe)
{
	CB.name = new char(sizeof(name)+1);
	strcpy(CB.name,name);
	CB.weight = weight;
	CB.energe = energe;
	return 0;
}

int ShowInfo(const CandyBar &CB)
{
	cout<<"Name: "<<CB.name<<endl;
	cout<<"\nweight: "<<CB.weight<<endl;
	cout<<"\nEnerge: "<<CB.energe<<endl;
	return 0;
}

int main()
{
	CandyBar CB;
	init(CB,(char*)"Millebmium Munch",2.85,350);
	ShowInfo(CB);
	return 0;
}
