#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define INF (1 << 30)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int mindist(vi& v)
{
    int min = INF;
    int i;
    rep(i,v.size()) cout << v[i] << " "; cout << endl;
    rep(i,v.size())
    {
        if (v[i] < min) min = v[i];
    }
    cout << "min: " <<  min << endl;
    return min;
}

int mindistsum(vvi& d, int L)
{
    //if (d.size() == 1) return mindist(d[0]);
    int i,j;
    int sum = 0;
    rep(i,d[0].size())
    {
        vi v;
        rep(j,d.size())
        {
            v.push_back(d[j][i]);
        }
        cout << sum << endl;
        sum += mindist(v) + L;
    }
    return sum;
}

int main()
{
    vvi a;
    vi x = {1,3,5};
    vi y = {2,4,6};
    a.push_back(x);
    //a.push_back(y);
    cout << mindistsum(a,0) << endl;

}
