#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define INF (1 << 30)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> ip;
typedef vector<ii> vii;
typedef vector<ip> vip;
typedef vector<vii> vvii;
typedef vector<vip> vvip;
typedef vector<int> vi;


int main()
{
    ip a = ip(0,ii(1,2));
    cout << a.first << endl;
    cout << a.second.first << endl;
    cout << a.second.second << endl;
}
