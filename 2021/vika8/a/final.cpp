#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define INF (1 << 30)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

vi dijkstra(vvii& g, int s)
{
	int i, x, w, n = g.size();
	vi d(n, INF); // Bestu gildin hingad til
	priority_queue<ii> q; // Geymir tvenndirnar (gildi, hnutur)
	q.push(ii(-0, s)); // Upphafshnutur
	d[s] = 0;
	while (q.size() > 0)
	{
		w = -q.top().first, x = q.top().second; q.pop();
		if (w > d[x]) continue; // thetta er urelt gildi
		rep(i, g[x].size()) if (d[g[x][i].first] > w + g[x][i].second)
		{
			q.push(ii(-(w + g[x][i].second), g[x][i].first));
			d[g[x][i].first] = w + g[x][i].second;
		}
	}
	return d;
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
	    vi d = dijkstra(g, s);
        rep(i,q)
        {
            cin >> query;
            if (d[query] != INF)
            {
                cout << d[query] << endl;
            }
            else cout << "Impossible" << endl;
        }
    }
}
