#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef vector<vi> vvi;

ll prim(vvii& g, vi& s, vi& v)
{
    //cout << g.size() << endl;
    int x, y, n = g.size();
    ll r = 0;
    priority_queue<ii,vii,greater<ii>> q;
    for(auto i : s) 
        for(auto j : g[i]) 
        {
            q.push(j);
            cout << q.top().first << endl;
        }
    while (q.size() > 0) 
    {
        x = q.top().second; 
        y = q.top().first; 
        q.pop();
        if(v[x]) continue;
        r += y;
        v[x] = 1;
        for (auto i : g[x]) 
        {
            q.push(i);
        }
    }
    return r;
}
int main() 
{
    int n;
    int i,j;
    cin >> n;
    rep(i,n)
    {
        int N, M, L, S;
        cin >> N >> M >> L >> S;

        vi s;
        vi v(N);
        rep(j,S)
        {
            int station;
            cin >> station;
            station--;
            v[station] = 1;
            s.push_back(station);
        }
        vvii g(N);
        rep(j,M)
        {
            int x, y, w;
            cin >> x >> y >> w;
            x--; y--;
            g[x].push_back(ii(w+L, y));
            g[y].push_back(ii(w+L, x));
        }
        cout << prim(g,s,v) << endl;
    }
}
