#include <iostream>  
using namespace std;  

const int seasons = 4; 
const char *season[seasons] = {"Spring","Summer","Fall","Winter"};
struct exp
{
	double expenses[seasons];
};

int fill(exp &exp)
{
 	for(int i=0;i<seasons;i++)
 	{
 		cout<<"Enter "<<*(season+i)<<" expenses : ";
 		cin>>exp.expenses[i];
 	}
 	cout<<"End;"<<endl;
 	return 0;
}



int show(const exp &exp)
{
	cout<<"Start : "<<endl;
	for(int i=0;i<seasons;i++)
	{
		cout<<"The "<<*(season+i)<<" expenses is "<<exp.expenses[i]<<endl;
	}
	cout << "End;"<<endl;
	return 0;
}

int main()  
{
	exp exp;
	fill(exp);
	show(exp);
	return 0;
}  