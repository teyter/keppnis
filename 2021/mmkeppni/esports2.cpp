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
        int n,m;
        cin >> n >> m;
        int a,b;
        cin >> a >> b;
        a--;b--;
	    vvii min(n);
        vvii max(n);
        int i;
        int u,v,w,dev;
        rep(i, m)
        {
            cin >> u >> v >> w >> dev;
            cout << u<<" "<<v<<" "<<w<<" "<<dev << endl;
            u--;v--;
            min[u].push_back(ii(v, w-dev));
            max[u].push_back(ii(v, w+dev));
        }
	    vi bmin = dijkstra(min, a);
	    vi bmax = dijkstra(max, a);
	    vi gmin = dijkstra(min, b);
	    vi gmax = dijkstra(max, b);
        int boo = 0;
        rep(i,n)
        {
            if (bmin[i] == gmin[i] || bmin[i] == gmax[i] || bmax[i] == gmin[i] || bmax[i] == gmax[i])
                if (bmin[i] != INF && gmin[i] != INF && bmax[i] != INF && gmax[i] != INF)
                {
                    cout << i+1 << " ";
                    boo = 1;
                }
        }
        if (boo == 0) cout << "Thessi leikur verdur sennilega leidinlegur";
        cout << endl;
}
