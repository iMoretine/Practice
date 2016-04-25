#include <iostream>
#include <vector>
using namespace std;

int findMidian(const vector<int> &arrayA, const vector<int> &arrayB)
{
    if(arrayA.empty() || arrayB.empty() || arrayA.size() != arrayB.size() )
        return 0;

    int startA = 0, endA = arrayA.size()-1;
    int startB = 0, endB = arrayB.size()-1;

    int tempMidIndexA;
    int tempMidIndexB;
    bool isALengthEven;
    bool isBLengthEven;
    while( startA < endA )
    {
        tempMidIndexA = (startA+endA)/2;
        tempMidIndexB = (startB+endB)/2;
        isALengthEven = (endA-startA+1)%2 == 0? true: false;
        isBLengthEven = (endB-startB+1)%2 == 0? true: false;
        
        if(arrayA[tempMidIndexA] > arrayB[tempMidIndexB])
        {
            endA = tempMidIndexA;
            startB = isBLengthEven? tempMidIndexB+1 : tempMidIndexB;
        }
        else if(arrayA[tempMidIndexA] < arrayB[tempMidIndexB])
        {
            startA = isALengthEven? tempMidIndexA+1 : tempMidIndexA;
            endB = tempMidIndexB;
        }
        else
            return arrayA[tempMidIndexA];
    }
    return arrayA[startA] < arrayB[startB] ? arrayA[startA] : arrayB[startB];
}

int main()
{
    int A[] = {11,13,15,17,19};
    int B[] = {2,4,6,8,20};
    vector<int> arrayA(A,A+5);
    vector<int> arrayB(B,B+5);
    cout<<findMidian(arrayA,arrayB)<<endl;
    return 0;
}