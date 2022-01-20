#include <iostream>
using namespace std;

long long gcd(long long M, long long N)
{
    if (N == 0)
        return M;
    return gcd(N, M % N);
}

int main()
{
    long long M, N;
    cin >> M >> N;
    long long g = gcd(M,N);
    M = M / g;
    N = N / g;
    if (M % 2 == 0 || N % 2 == 0)
        g = 0;
    cout << g << endl;
}
