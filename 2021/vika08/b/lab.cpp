#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define INF (1 << 30)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

int bellman_ford(vvii& g, int s, int q)
{
	int i, k, n = g.size(), x, w;
	vi d(g.size(), INF);
	d[s] = 0;
    if (d[q] != INF) 
        rep(k, g[q].size())
	        d[g[q][k].first] = min(d[g[q][k].first], d[q] + g[q][k].second);

    if (d[q] != INF) 
        rep(k, g[q].size())
        {
            x = g[q][k].first, w = g[q][k].second;
            if (d[x] != -INF && d[q] + w < d[x]) d[x] = -INF;
        }
	return d[q];
}

int main()
{
    int i,j,n,m,q,s,u,v,w,query;
    int counter = 0;
    while (true)
    {
        cin >> n >> m >> q >> s;
        if (n == 0 && m == 0 && q == 0 && s == 0) break;
        if (counter > 0) cout << endl; 
        counter = 1;
	    vvii g(n);
        rep(i, m)
        {
            cin >> u >> v >> w;
            g[u].push_back(ii(v, w));
        }
        rep(i,q)
        {
            cin >> query;
	        int d = bellman_ford(g, s, query);
            if (d == INF)
            {
                cout << "Impossible" << endl;
            }
            else if (d == -INF)
            {
                cout << "-Infinity" << endl;
            }
            else cout << d << endl;
        }
    }
}
