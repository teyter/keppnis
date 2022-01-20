#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

ll prim(vvii& g, vi& s)
{
    int i, j, x, y, w, n = g.size();
    ll r = 0;
    vi v(n);
    priority_queue<iii> q;
    for (i = 0; i < s.size(); i++)
    {
        v[s[i]] = 1;
        for (j = 0; j < g[s[i]].size(); j++)
        {
            q.push(iii(-g[s[i]][j].second,ii(g[s[i]][j].first,s[i])));
        }
    }
    while (q.size() > 0)
    {
        iii p = q.top(); 
        q.pop();
        w = -p.first;
        x = p.second.first;
        y = p.second.second;
        if (v[x] == 1) continue;
        r += w;
        v[x] = 1;
        for (i = 0; i < g[x].size(); i++)
        {
            q.push(iii(-g[x][i].second, ii(g[x][i].first, x)));
        }
    }
    return r;
}

int main()
{
    int n;
    int i, j;
    cin >> n;
    rep(i,n)
    {
        int N, M, L, S;
        cin >> N >> M >> L >> S;
        vi s;
        rep(j,S)
        {
            int station;
            cin >> station;
            station--;
            s.push_back(station);
        }
        vvii g(N);
        rep(j,M)
        {
            int x, y, w;
            cin >> x >> y >> w;
            x--, y--;
            w += L;
            g[x].push_back(ii(y, w));
            g[y].push_back(ii(x, w));
        }
        cout << prim(g,s) <<  endl;
    }
    return 0;
}
