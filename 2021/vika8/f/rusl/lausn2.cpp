#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define INF (1 << 30)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef vector<vi> vvi;
void printvv(vvi& g)
{
    for (int i = 0; i < g.size(); i++)
    {
        cout << i << ": ";
        for (int j = 0; j < g[i].size(); j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}
void printv(vi& g)
{
    for (int i = 0; i < g.size(); i++)
    {
        cout << g[i] << " ";
    }
    cout << endl;
}

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

int mindist(vi& v)
{
    int min = INF;
    int i;
    rep(i,v.size())
    {
        if (v[i] < min) min = v[i];
    }
    return min;
}

int mindistsum(vvi& d, int L)
{
    int i,j;
    int sum = 0;
    rep(i,d[0].size())
    {
        vi v;
        rep(j,d.size())
        {
            v.push_back(d[j][i]);
        }
        sum += mindist(v) + L;
    }
    return sum-L;
}
// Fyrsta lína inntaksins eru tvær heiltölur, fjöldi hnúta og fjöldi leggja.
// Síðan koma m línur sem svara til leggjalistans.
int main()
{
    int n;
    int i, j, k;
    cin >> n;
    int N, M, L, S;
    vi s;
    int station;
    int x, y, w;
    int sum;
    rep(i,n)
    {
        cin >> N >> M >> L >> S;
        vvi d(S);
        //cout << N <<" "<< M <<" "<< L <<" "<< S << endl;
        rep(j,S)
        {
            cin >> station;
            station--;
            //cout << station;
            s.push_back(station);
        }
        //cout << endl;
	    vvii g(N);
        rep(j,M)
        {
            cin >> x >> y >> w;
            //cout << x <<" "<< y <<" "<< w << endl;
            x--, y--;
            w += L;
            g[x].push_back(ii(y, w));
		    g[y].push_back(ii(x, w)); // Sleppa þesari línu ef netið er stefnt.
        }
        rep(j,S)
        {
            vi dd = dijkstra(g, s[j]);
            rep(k,N) cout << "k: " << dd[k] << " " << endl;
	        d[j] = dd;
        }
        cout << mindistsum(d,L) << endl;
        printvv(d);
    }
	return 0;
}
