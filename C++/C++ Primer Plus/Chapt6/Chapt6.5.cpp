#include <iostream>
using namespace std;

int main()
{
	int salary;
	int tax;
	cout<<"Enter your salary:"<<endl;
	cin>>salary;

	while(salary>=0)
	{
		if(salary<=5000)
			tax = 0;
		else if(salary <= 15000)
			tax = (salary-5000)*0.1;
		else if(salary <= 35000)
			tax = 10000 * 0.1 + (salary-15000)*0.15;
		else if(salary >35000)
			tax = 10000* 0.1 + 20000 * 0.15 + (salary-35000)*0.2;	
		cout << "Your tax is "<<tax<<endl;

		cout<<"Enter your salary:";  
        		cin>>salary; 
	}

	return 0;
}