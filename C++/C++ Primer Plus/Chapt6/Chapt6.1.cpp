#include <iostream>
#include <cctype>

using namespace std;

int main()
{
	cout << "Enter text for analysis, and type @ to terminate input."<<endl;
	char ch;

	cin.get(ch);
	while(ch != '@')
	{
		if(islower(ch))
			cout<<char(ch-32)<<endl;
		if(isupper(ch))
			cout<<char(ch+32)<<endl;
		cin.get(ch);
	}

	return 0;
}