#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct donation
{
	string name;
	double sum;
};
int main()  
{
	ifstream inFile;
	inFile.open("Chapt6.9.txt");
	if(!inFile.is_open())
	{
		cout<<"Open Failed!"<<endl;
	}

	int number;
	inFile >> number;
	inFile.get();
	donation *donate = new donation[number];
	donation *p = donate;

	for(int i=0;i<number;i++)
	{
		getline(inFile,p->name);
		inFile >> p->sum;
		inFile.get();
		p++;
	}
	inFile.close();


	cout<<"Grand Patrons : "<<endl; 
	p = donate;
	for(int i=0;i<number;i++)
	{
		if(p->sum >= 10000)
			cout << p->name << " "<< p->sum<<endl;
		p++;
	}

	cout<<"Patrons : "<<endl; 
	p = donate;
	for(int i=0;i<number;i++)
	{
		if(p->sum < 10000)
			cout << p->name << " "<< p->sum<<endl;
		p++;
	}


	return 0;
}  