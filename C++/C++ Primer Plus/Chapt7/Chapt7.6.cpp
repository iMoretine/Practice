#include <iostream>
using namespace std;

int Fill_array(double arr[],int arrSize)
{
	int count = 0;
	for(int i=0;i<arrSize;i++)
	{
		cout<<"Enter the "<<i+1<<"values : ";
		if(!(cin>>arr[i]))
		{
			break;
		}
		count = i;
	}
	cout<<"You have entered "<<count<<" values!\n";
	return count;
}

int Show_array(const double arr[],int arrSize)
{
	cout<<"Array : \n";
	for(int i=0;i<arrSize;i++)
		cout<<arr[i]<<"  ";
	cout<<"\nEnd;\n";
	return 0;
}

int Reverse_array(double arr[],int arrSize)
{
	int temp;
	cout<<"\nnow Reverse the array!"<<endl;
	for(int i=1;i<arrSize/2;i++)
	{
		temp = arr[i];
		arr[i] = arr[arrSize-1-i];
		arr[arrSize-1-i] = temp;
	}
	cout << "this is the new array : "<<endl;
	Show_array(arr,arrSize);
	return 0;
}

int main()
{
	double arr[10];
	int count;
	count = Fill_array(arr,10);
	Show_array(arr,count);
	Reverse_array(arr,count);
	return 0;
}