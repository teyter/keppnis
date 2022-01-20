#include <stdio.h>

int fib(int n, int memo[])
{
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (!memo[n]) {
        memo[n] = fib(n-1,memo) + fib(n-2,memo);
    }
    return memo[n];
}

int main()
{
    int n;
    scanf("%d", &n);
    int memo[n];
    printf("%d\n", fib(n,memo));
    return 0;
}
