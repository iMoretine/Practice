#include <iostream>
using namespace std;

struct  box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

int showValue(const box b)
{
	cout<<"maker : "<<b.maker<<endl;
	cout<<"height : "<<b.height<<endl;
	cout<<"width : "<<b.width<<endl;
	cout<<"length : "<<b.length<<endl;
	cout<<"volume : "<<b.volume<<endl;
	return 0 ;
}	

int setValue(box &b)
{
	b.volume = b.height*b.width*b.length;
	return 0;
}

int main()
{
	box b = {"myBOX",2,4,2,0};
	cout<<"Value : "<<endl;
	showValue(b);
	cout<<"After set : "<<endl;
	setValue(b);
	showValue(b);
	return 0;
}