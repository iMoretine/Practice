#include <iostream>
#include <vector>
using namespace std;

void swap(int &c1,int &c2)
{
    int t = c1;
    c1 = c2;
    c2 = t;
}

void reverse(vector<int> &array, int start, int end)
{
    for(int i=start,j=end;i<j;i++,j--)
        swap(array[i],array[j]);
}

void rotate(vector<int> &array, int n)
{
    n = n%array.size();
    reverse(array,0,n-1);
    reverse(array,n,array.size()-1);
    reverse(array,0,array.size()-1);
}

int main(int argc, char const *argv[])
{
    // Test case.
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> array(a,a+10);
    cout<<"Array :"<<endl;
    for(int i=0;i<array.size();i++)
        cout<<array[i]<<" ";
    cout<<endl;

    cout<<"Rotate left 4 units :"<<endl;
    rotate(array,4);
    for(int i=0;i<array.size();i++)
        cout<<array[i]<<" ";
    cout<<endl;
    return 0;
}