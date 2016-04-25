#include <stdio.h>
#include <stdlib.h>

#define N 10000
#define K 100

int n[N];

int randInt(int l, int u)
{
    return (double)rand()/RAND_MAX*(u-l+1)+l;
}

int swap(int a, int b)
{
    int t = n[a];
    n[a] = n[b];
    n[b] = t;
    return 0;
}

int main(int argc, char const *argv[])
{
    int i;
    for(i = 0;i<N;i++)
        n[i] = i;
    for(i = 0;i<K;i++)
    {
        swap(i, randInt(i,N-1));
        printf("%d\n",n[i]);
    }
    return 0;
}