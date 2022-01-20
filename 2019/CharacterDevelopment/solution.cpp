#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef pair<int,int> ii;
typedef map<pair<int,int>, int> miii;

int partitions(miii& memo, int P, int m, int power) 
{
    if(P == 0) return 1;
    if(power <= 0) return 0;
    if(power == 1) return 1;

    ii i = {P, power};

    if(memo.count(i)) return memo[i];

    int sum = 0;

    if(P >= power) sum = partitions(memo, P-power, m, power);
    if(power >= 1) sum += partitions(memo, P, m, power/m);
    
    memo[i] = sum;
    return sum;
}

int main() 
{
    int P;
    cin >> P;
    int i;

    rep(i, P)
    {
        int K, m, n;
        cin >> K >> m >> n;
        cout << K;

        miii memo;
        int power = m;

        while(power <= n) 
        {
            power *= m;
        }
        cout << " " << partitions(memo, n, m, power) << endl;
    }
}
