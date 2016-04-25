#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int ToUpper(string &str)
{
	int length = str.length();
	for(int i=0;i<length;i++)
	{
		str[i] = toupper(str[i]);
	}
	return 0;
}

int main()
{
	string str = "Hello world!";
	cout<<str<<endl;
	ToUpper(str);
	cout<<str<<endl;
}