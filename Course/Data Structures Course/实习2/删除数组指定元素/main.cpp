#include <iostream>
#include <vector>
using namespace std;

void deleteN(vector<int> &array, int n)
{
    int indexRead = 0, indexWrite = 0;
    while(indexRead < array.size())
    {
        if(array[indexRead] != n)
        {
            array[indexWrite] = array[indexRead];
            indexWrite++;
        }
        indexRead++;
    }
    int L = array.size();
    for(int i=indexWrite;i<L;i++)
        array.pop_back();
}

int main(int argc, char const *argv[])
{
    // Test case.
    int a[] = {3,2,3,4,3};
    vector<int> array(a,a+5);
    cout<<"Array :"<<endl;
    for(int i=0;i<array.size();i++)
        cout<<array[i]<<" ";
    cout<<endl;

    cout<<"Delete 3 :"<<endl;
    deleteN(array,3);
    for(int i=0;i<array.size();i++)
        cout<<array[i]<<" ";
    cout<<endl;
    return 0;
}