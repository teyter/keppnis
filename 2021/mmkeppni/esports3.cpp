#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define INF (1 << 31)
using namespace std;
typedef pair<long long, long long> ii;
typedef pair<long long, ii> ip;
typedef vector<ii> vii;
typedef vector<ip> vip;
typedef vector<vii> vvii;
typedef vector<vip> vvip;
typedef vector<long long> vi;

vii dijkstra(vvip& g, long long s)
{
	long long i, x, w, dev, n = g.size();
	vii d(n, ii(INF,INF)); // Bestu gildin hingad til
	priority_queue<ip> q; // Geymir tvenndirnar (gildi, hnutur)
	q.push(ip(-0, ii(s,-0))); // Upphafshnutur
	d[s].first = 0;
	d[s].second = 0;
	while (q.size() > 0)
	{
		w = -q.top().first;
        x = q.top().second.first; 
        dev = -q.top().second.second;
        q.pop();
		if (w > d[x].first) continue; // thetta er urelt gildi
		rep(i, g[x].size()) 
            if (d[g[x][i].first].first > w + g[x][i].second.first)
            {
                q.push(ip(-(w + g[x][i].second.first), ii(g[x][i].first, -(dev + g[x][i].second.second))));
                d[g[x][i].first].first = w + g[x][i].second.first;
                d[g[x][i].first].second = dev + g[x][i].second.second;
            }
	}
	return d;
}

int main()
{
        long long n,m;
        cin >> n >> m;
        long long a,b;
        cin >> a >> b;
        a--;b--;
        long long i;
        long long u,v,w,dev;
        vvip g(n);
        rep(i, m)
        {
            cin >> u >> v >> w >> dev;
            u--;v--;
            g[u].push_back(ip(v, ii(w,dev)));
        }
        //cout << g[0][0].second.second << endl;
	    vii ct = dijkstra(g, a);
	    vii t = dijkstra(g, b);
        long long ctmax,ctmin,tmax,tmin;
        bool boo = true;
        rep(i,n)
        {
            ctmax = ct[i].first + ct[i].second;
            ctmin = ct[i].first - ct[i].second;
            tmax = t[i].first + t[i].second;
            tmin = t[i].first - t[i].second;
            if (ct[i].first != INF && t[i].first != INF)
            if ((ctmax >= tmax && tmax >= ctmin) || (ctmax >= tmin && tmin >= ctmin) || (tmax >= ctmax && ctmax >= tmin) || (tmax >= ctmin && ctmin >= tmin))
            {
                cout << i+1 << " ";
                b = false;
            }
        }
            if (b) cout << "Thessi leikur verdur sennilega leidinlegur";
            cout << endl;
}
