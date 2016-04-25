#include <stdio.h>
#include <stdlib.h>

int intComp(int *x, int *y)
{
    return *x - *y;
}

int a[1000000];

int main(int argc, char const *argv[])
{
    int i, n = 0;
    printf("Input numbers(Enter EOF end the input):\n");
    while (scanf("%d", &a[n]) != EOF )
        n++;
    printf("Result:\n");
    qsort(a, n, sizeof(int), intComp);
    for(i = 0; i < n; i++)
        printf("%d\n", a[i]);
    return 0;
}