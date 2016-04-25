#include <iostream>
using namespace std;
#include <cstring>

struct stringy
{
	char * str;
	int ct;
};

int set(stringy &beany,const char t[])
{
	beany.str = new char(strlen(t)+1);
	strcpy(beany.str , t);
	beany.ct = strlen(beany.str);
	return 0;
}

int show(const stringy &beany,int count = 0)
{
	if(count != 0)
	{
		for(int j=0;j<count;j++)
		{
			cout<<beany.str<<endl;
		}
	}
	else
		cout<<beany.str<<endl;
	return 0;
}

int show(const char t[],int count = 0)
{
	if(count != 0)
	{
		for(int j=0;j<count;j++)
		{
			cout<<t<<endl;
		}
	}
	else
		cout<<t<<endl;
	return 0;
}

int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	set(beany,testing);

	show(beany);
	show(beany,2);
	
	testing[0] = 'D';
	testing[1] = 'u';

	show(testing);
	show(testing,3);
	show("Done!");
	return 0;
}