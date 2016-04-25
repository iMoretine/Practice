#include <iostream>
#include <cstring>

int main()
{
	using namespace std;
	char firstname[20];
	char lastname[20];
	cout <<"Enter your first name: ";
	cin.getline(firstname,20);
	cout << "Enter you last name: ";
	cin.getline(lastname,20);

	strcat(firstname,",");
	strcat(firstname,lastname);
	cout<<"Here's the information in a single string "<<firstname<<endl;

	return 0;
}
