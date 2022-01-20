#include <stdio.h>
#define MAXN 1000000

int d[MAXN];

int fib(int x)
{
    if (d[x] != -1) return d[x];
    if (x < 2) return 1;
    return d[x] = fib(x-1) + fib(x-2);
}

int main()
{
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) d[i] = -1;
    printf("%d\n", fib(n));
    return 0;
}
