#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string firstname;
	string lastname;
	cout <<"Enter your first name: ";
	getline(cin,firstname);
	cout << "Enter you last name: ";
	getline(cin,lastname);
	
	firstname+=" ,";
	firstname+=lastname;
	cout<<"Here's the information in a single string "<<firstname<<endl;

	return 0;
}
