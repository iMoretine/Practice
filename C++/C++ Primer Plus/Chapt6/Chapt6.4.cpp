#include <iostream>
using namespace std;

struct bop
{
	char fullname[20];
	char title[20];
	char bopname[20];
	int perference;
};

int main()
{
	bop menber[5] = {{"Wimp macho","Coder","Wimp",1},
				{"Raki Rhodes","Junior Programer","Raki",2},
				{"Celia Laiter","MIPS","Celia",2},
				{"Hoppy Hipman","Coder","Analyst Trainee",3},
				{"Pat Hand","Coder","LOOPY",3}};

	cout<<"Benevolent order of Programmers Report"<<endl;  
    	cout<<"a.display by name              b.display by title"<<endl;  
    	cout<<"c.display by bopname           d.display by priference"<<endl;  
    	cout<<"q.quit"<<endl;
    	cout<<"Enter your choice:"; 

    	char ch;  
    	cin>>ch;

    	while(ch!='q')
    	{
    		switch(ch)
    		{
    			case 'a':
	    			for(int i=0;i<5;i++)
	    			{  
	        				cout<<menber[i].fullname<<endl;  
	             			};
	             			break;  

    			case 'b':
	    			for(int i=0;i<5;i++)
		    		{  
		        			cout<<menber[i].title<<endl;  
		             		};
		             		break;

    			case 'c':
    				for(int i=0;i<5;i++)
		    		{  
		        			cout<<menber[i].bopname<<endl;  
		             		};
		             		break;
    			case 'd':
    				for(int i=0;i<5;i++)
		    		{ 
		             			switch(menber[i].perference)
		             			{
		             				case 1:
		             					cout<<menber[i].fullname<<endl;break;
		             				case 2:
		             					cout<<menber[i].title<<endl;break;
		             				case 3:
		             					cout<<menber[i].bopname<<endl;break;
		             			}
		             		};
		             		break;
    		}
    		cout<<"Next Choice:";  
   		cin>>ch;  
    	}
    	cout<<"bye"<<endl; 
	
	return 0;
}