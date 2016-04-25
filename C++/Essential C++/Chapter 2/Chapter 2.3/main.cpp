#include <vector>
#include <string>
#include <iostream>
using namespace std;

void display_elems( vector<int> &vec, const string &title, ostream &os=cout );
void really_calc_elems( vector<int>&, int );

inline bool calc_elems( vector<int> &vec, int pos )
{
    if ( pos <= 0 || pos > 64 )
    {
        cerr << "Sorry. Invalid position: " << pos << endl;
        return false;
    }
    if ( vec.size() < pos )
    really_calc_elems( vec, pos );
    return true;
}

int main()
{
    vector<int> pent;
    const string title( "Pentagonal Numeric Series" );
    if ( calc_elems( pent, 0 ))
        display_elems( pent, title );
    if ( calc_elems( pent, 8 ))
        display_elems( pent, title );
    if ( calc_elems( pent, 14 ))
        display_elems( pent, title );
    if ( calc_elems( pent, 138 ))
        display_elems( pent, title );
}

void really_calc_elems( vector<int> &vec, int pos )
{
    for ( int ix = vec.size()+1; ix <= pos; ++ix )
        vec.push_back( (ix*(3*ix-1))/2 );
}

void display_elems( vector<int> &vec, const string &title, ostream &os )
{
    os << '\n' << title << "\n\t";
    for ( int ix = 0; ix < vec.size(); ++ix )
        os << vec[ ix ] << ' ';
    os << endl;
}