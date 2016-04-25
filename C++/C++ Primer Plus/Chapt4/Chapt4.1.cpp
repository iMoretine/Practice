#include <iostream>

int main()
{
	using namespace std;
	char firstname[20];
	char lastname[20];
	char Letter;
	short age;

	cout << "What is your first name ? ";
	cin.getline(firstname,20);
	cout << "What is your last name ? ";
	cin.getline(lastname,20);
	cout << "What letter grade do you deserve ? ";
	cin >> Letter;
	cout <<"What is your age ? ";
	cin >> age;

	cout << "Name : " << lastname << " , "<<firstname <<endl;
	cout << "Grade : " << char(Letter+1) << endl;
	cout << "Age : " << age << endl;
	return 0;
}