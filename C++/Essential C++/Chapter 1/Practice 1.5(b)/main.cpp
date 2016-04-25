#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
    // must allocate a fixed size
    const int nm_size = 128;
    char user_name[ nm_size ];
    cout << "Please enter your name: ";
    cin >> setw( nm_size ) >> user_name;
    switch ( strlen( user_name ))
    {
    // same case labels for 0, 1
    case 127:
        // maybe string was truncated by setw()
        cout << "That is a very big name, indeed -- "
             << "we may have needed to shorten it!\n"
             << "In any case,\n";
        // no break -- we fall through ...
    default:
        // the 127 case drops through to here -- no break
        cout << "Hello, " << user_name
             << " -- happy to make your acquaintance!\n";
        break;
    }
    return 0;
}
