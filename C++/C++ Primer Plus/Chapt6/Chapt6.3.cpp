#include <iostream>
using namespace std;

int main()
{
	cout << "Please enter one of the following choices : "<<endl;
	cout << "c) carnivore                              p) pianist"<<endl;
	cout << "t) tree                                        g) game<<"<<endl<<endl;
	char ch;

	bool flag = true;
	while(flag)
	{
		cout << "Please enter  a c, p, t, or g: "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 'c':
				cout<<"A mape is a carnivore"<<endl,flag=false;break;
			case 'p':
				cout<<"A mape is a pianist"<<endl,flag=false;break;
			case 't':
				cout<<"A mape is a tree"<<endl,flag=false;break;
			case 'g':
				cout<<"A mape is a game"<<endl,flag=false;break;
			default: ;
		}
	}
	return 0;
}