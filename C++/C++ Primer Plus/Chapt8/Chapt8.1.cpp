#include <iostream>
#include <string>
using namespace std;

int print(const string &s,int count=0);

static int number=0;//记录被调用的次数

int main()
{
	print("Call 01");
	print("Call 02",0);
	print("Call 03",200);
	return 0;
}

int print(const string &s,int count)
{
	if(count==0)
	{
		cout<<s<<endl;
	}
	else
	{
		for(int i=0;i<number;i++)
			cout<<s<<endl;
	}
	number++;
	return 0;
}