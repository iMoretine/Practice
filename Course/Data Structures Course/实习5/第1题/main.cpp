#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int x,y;
    Node(int _x,int _y):x(_x),y(_y){}
};

vector<int> printMaxtrix(vector<vector<int> > matrix)
{
    vector<int> result;
    int m = matrix.size();
    if(m == 0)
        return result;
    int n = matrix[0].size();
    if(n == 0)
        return result;

    Node a(0,0);
    Node b(m-1,n-1);
    int e = m < n ? m : n;
    e = e/2;
    while(e--)
    {
        for(int i=a.y;i<=b.y;i++)
            result.push_back(matrix[a.x][i]);
        for(int i=a.x+1;i<=b.x;i++)
            result.push_back(matrix[i][b.y]);
        for(int i=b.y-1;i>=a.y;--i)
            result.push_back(matrix[b.x][i]);
        for(int i=b.x-1;i>a.x;i--)
            result.push_back(matrix[i][a.y]);
        a.x++;
        a.y++;
        b.x--;
        b.y--;
    }
    if(a.x == b.x)
    {
        for(int i=a.y;i<=b.y;i++)
            result.push_back(matrix[a.x][i]);
    }
    else if (a.y == b.y)
    {
        for(int i=a.x;i<=b.x;i++)
            result.push_back(matrix[i][a.y]);
    }
    return result;
}

int main()
{
    int a[] = {1,2,3,4};
    int b[] = {5,6,7,8};
    int c[] = {9,10,11,12};
    int d[] = {13,14,15,16};
    vector<vector<int> > m;
    m.push_back(vector<int>(a,a+4));
    m.push_back(vector<int>(b,b+4));
    m.push_back(vector<int>(c,c+4));
    m.push_back(vector<int>(d,d+4));
    vector<int> r = printMaxtrix(m);
    for(int i=0;i<r.size();i++)
        cout<<r[i]<<" ";
    cout<<endl;
    return 0;
}