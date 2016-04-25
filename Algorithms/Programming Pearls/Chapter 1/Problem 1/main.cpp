#include <iostream>
#include <set>
using namespace std;

int main(int argc, char const *argv[])
{
    set<int> S;
    int i;
    set<int>::iterator j;
    cout<<"Input numbers(Enter EOF end the input):\n";
    while(cin >> i)
        S.insert(i);
    cout<<"Result\n";
    for(j = S.begin(); j != S.end(); ++j)
        cout << *j << endl;
    return 0;
}
