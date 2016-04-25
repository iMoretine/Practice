#include <iostream>
using namespace std;
const int ArrSize = 10;

int inputGrade (int grade[])
{
	int count;
	int input;
	cout << "Enter the grade (nagative number for quit) : "<<endl;
	cin>>input;
	for(int i=0;i<ArrSize;i++)
	{
		if(input<0) 
		{
			count = i;
			break;
		}
		else
		{
			grade[i] = input;
			cout << "Enter the next grade : "<<endl;
			cin >> input;
		}
	}
	grade[count] = -1;
	return 0;
}

int showGrade(int grade[])
{
	cout << "The grade is : "<<endl;
	for(int i=0;i<ArrSize;i++)
	{
		if(grade[i] == -1) 
			break;
		else
			cout << grade[i] << "  ";
	}
	cout<<endl;
	return 0;
}

int getAvgGrade(int grade[])
{
	double sum=0;
	int count;
	for(int i=0;i<ArrSize;i++)
	{
		if(grade[i] == -1) 
		{
			count = i;
			break;
		}
		else
		{
			sum+=grade[i];
		}
	}
	cout << "The average grade is : "<<sum / count<<endl;
	return 0;
}

int main()
{
	int grade[ArrSize];
	inputGrade(grade);
	showGrade(grade);
	getAvgGrade(grade);

	return 0;
}