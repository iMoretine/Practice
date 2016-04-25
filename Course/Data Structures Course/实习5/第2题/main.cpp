#include <iostream>
#include <vector>
using namespace std;

int findNumber(vector<int> num)
{
    if(num.size() == 0)
        return 0;
    if(num.size() == 1)
        return num[0];
    int count = 1;
    int result = num[0];
    for(int i=1;i<num.size();i++)
    {
        if(num[i] == result)
            count ++;
        else
            count --;
        if(count == 0)
        {
            result = num[i];
            count = 1;
        }
    }
    return result;
}

int main()
{
    int a[] = {1,2,3,2,2,2,5,4,2};
    vector<int> num(a,a+9);
    cout<<findNumber(num)<<endl;
    return 0;
}