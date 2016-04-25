#include <iostream>
#include <cstring>

using namespace std;  

const int SLEN = 30; 
struct student
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student pa[],int n)
{
	int count = 0;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the name of student "<<i+1<<" (blank for done) : ";
		cin.get();
		cin.getline(pa[i].fullname,20);
		if (strcmp(pa[i].fullname,"") == 0)
		{
			cout<<"Enter done."<<endl;
			break;
		}
		cout<<"Enter the hobby : ";
		cin>>pa[i].hobby;
		cout<<"Enter the ooplevel : ";
		cin>>pa[i].ooplevel;
		count++;
	}
	return count;
}

void display1(student st)
{
	cout<<"[Display1]:"<<endl;
	cout<<"  fullname : "<<st.fullname<<endl;
	cout<<"  hobby : "<<st.hobby<<endl;
	cout<<"  ooplevel : "<<st.ooplevel<<endl;
}

void display2(const student * ps)
{
	cout<<"[Display2]:"<<endl;
	cout<<"  fullname : "<<ps->fullname<<endl;
	cout<<"  hobby : "<<ps->hobby<<endl;
	cout<<"  ooplevel : "<<ps->ooplevel<<endl;
}

void display3(const student pa[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"[Display3]:"<<endl;
		cout<<"  fullname : "<<pa[i].fullname<<endl;
		cout<<"  hobby : "<<pa[i].hobby<<endl;
		cout<<"  ooplevel : "<<pa[i].ooplevel<<endl;
	}
}

int main()  
{
	cout <<"Enter class size: ";
	int class_size;
	cin >> class_size;

	while(cin.get() != '\n')
		continue;

	student * ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu,class_size);

	for(int i=0;i<entered;i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu,entered);

	delete [] ptr_stu;
	cout << "Display Done."<<endl;
	return 0;
}  