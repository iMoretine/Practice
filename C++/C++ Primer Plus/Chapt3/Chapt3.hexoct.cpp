#include <iostream>
int main()
{
	using namespace std;
	int chest = 42;
	int waist = 0x42;
	int inseam = 042;

	cout << "Monsieur cuts astriking figure!\n";
	cout << "chest = "<< chest << " demical \n";
	cout << "waist = "<< waist << " hex \n";
	cout << "inseam = " << inseam << " octal\n";

	cout << hex;
	cout << "chest = "<< chest << " hex \n";
	cout << oct;
	cout << "chest = "<< chest << " octal\n";
	return 0; 
}
