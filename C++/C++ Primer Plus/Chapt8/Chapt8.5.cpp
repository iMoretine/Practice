#include <iostream>

using namespace std;

template <typename T> 
T max5(T array[])
{
	T max = 0;
	for(int i=0;i<5;i++)
	{
		if ( array[i] > max )
			max = array[i];
	}
	return max;
}

int main()
{
	double arr1[5] = {1,2,3,4,5};
	int arr2[5] = {2,3,4,5,6};
	cout<<max5(arr1)<<endl;
	cout<<max5(arr2)<<endl;
	return 0;
}