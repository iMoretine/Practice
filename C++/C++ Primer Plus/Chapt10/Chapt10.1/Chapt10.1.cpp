#include <iostream>
#include "Acount.h"

using namespace std;

void main()
{
	Acount A1 = Acount("Name01","Acount01",1000);
	Acount A2 = Acount("Name02","Acount02",2000);
	cout<<A1<<endl;
	cout<<A2<<endl;
	A1.in(100);
	A1.showInfo();
	A1.out(50);
	A1.showInfo();
}