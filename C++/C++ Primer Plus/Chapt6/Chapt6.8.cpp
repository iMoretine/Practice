#include <fstream>
#include <iostream>

using namespace std;

int main()  
{
	ifstream inFile;
	int count = 0;
	inFile.open("Chapt6.8.txt");
	if(!inFile.is_open())
	{
		cout<<"Open Failed!"<<endl;
	}
	char ch;
	inFile>>ch;
	while(inFile.good())
	{
		count++;
		inFile>>ch;
	}
	if(inFile.eof())
	{
		cout<<"count = "<<count<<endl;
	}
	inFile.close();
	return 0;
}  