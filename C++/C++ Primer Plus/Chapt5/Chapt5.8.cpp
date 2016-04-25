#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int count = 0;
	char word[20];
	cout<<"Enter words (to stop , type the word done) : "<<endl;
	cin>>word;
	while(strcmp(word,"done")!=0)
	{
		count++;
		cin>>word;
	}
	cout<<"You entered a total of "<<count<<" words."<<endl;
	return 0;
}