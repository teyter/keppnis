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

// Fyrsta lína inntaksins eru tvær heiltölur, fjöldi hnúta og fjöldi leggja.
// Síðan koma m línur sem svara til leggjalistans.
int main()
{
    int n;
    int i, j, k;
    cin >> n;
    cout << n << endl;
    int N, M, L, S;
    vi initial_stations;
    int s;
    int x, y, w;
    int sum;
    rep(i,n)
    {
        cin >> N >> M >> L >> S;
        cout << N <<" "<< M <<" "<< L <<" "<< S << endl;
        rep(j,S)
        {
            cin >> s;
            cout << s;
            initial_stations.push_back(s);
        }
        cout << endl;
	    vvii g(N);
        rep(j,M)
        {
            cin >> x >> y >> w;
            cout << x <<" "<< y <<" "<< w << endl;
            x--, y--;
            g[x].push_back(ii(y, w));
		    g[y].push_back(ii(x, w)); // Sleppa þesari línu ef netið er stefnt.
        }
	    vi d = dijkstra(g, 2);
        rep(j,N)
        {
            cout << j+1 << " " << d[j] << endl;
        }
    }
	return 0;
}
