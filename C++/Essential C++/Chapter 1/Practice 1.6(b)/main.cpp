#include <iostream>
using namespace std;

int main()
{
    const int array_size = 128;
    int ia[ array_size ];
    int ival, icnt = 0;
    while ( cin >> ival &&icnt < array_size )
        ia[ icnt++ ] = ival;
    int sum = 0;
    for ( int ix = 0; ix < icnt; ++ix )
        sum += ia[ ix ];
    int average = sum / icnt;
    cout << "Sum of " << icnt
         << " elements: " << sum
         << ". Average: " << average << endl;
}
