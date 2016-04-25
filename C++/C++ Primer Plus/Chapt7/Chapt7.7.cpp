#include <iostream>  
using namespace std;  

const int MAX=10;  

double* Fill_array(double *arr)   
{  
    	double *p=arr;
    	int count = 0;
    	for(int i=0;i<MAX;i++)
    	{
        		cout<<"Enter the "<<i+1<<" values:";
        		if(cin>>*p)
        		{
            			p++;
            			count = i;
        		}
        		else
            			break;
    	}
    	cout<<"You have entered "<<count<<"  values."<<endl;

    	return p;
} 
  
int const Show_array(const double *arr,double *end)  
{  
    	const double *p=arr;  
    	cout<<"the array is:"<<endl;  
    	while(p<end)
    	{
    		cout<<*p<<"  ";
    		p++;
    	} 
    	cout<<"End!"<<endl;

    	return 0;
}

int revalue(double r,double *arr,double *end)  
{
	double *p = arr;
    	while(p<end) 
    	{  
    		*p *=r;
    		p++;
    	}  
    	cout<<"this is the new array:"<<endl;  
    	Show_array(arr,end);
    	return 0;
}  

int main()  
{  
    	double arr[MAX];  
    	double *end=Fill_array(arr); 
    	Show_array(arr,end);  
    	revalue(3.0,arr,end);  
	return 0;
}  