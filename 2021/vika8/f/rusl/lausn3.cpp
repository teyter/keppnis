#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

ll prim(vvii& g, vi& s, vi& v)
{
	int i, j, x, y, w, n = g.size();
    ll r = 0;
	priority_queue<iii> q;
    rep(i,s.size())
        rep(j,g[i].size())
            q.push(iii(-g[s[i]][j].second,ii(g[s[i]][j].first,s[i])));
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
		rep(i, g[x].size()) 
        //cout << q.size() << endl;
            if (v[g[x][i].first] == 0)
			    q.push(iii(-g[x][i].second, ii(g[x][i].first, x)));
	}
	return r;
}
int main()
{
    int i, j;
    int n;
    cin >> n;
    cout << n << endl;
    rep(i,n)
    {
        int N, M, L, S;
        cin >> N >> M >> L >> S;
        cout<<N<<" "<<M<<" "<<L<<" "<<S<<endl;
        vi s;
        vi v(N);
        rep(j,S)
        {
            int station;
            cin >> station;
            cout << station << " ";
            station--;
            v[station] = 1;
            s.push_back(station);
        }
        cout << endl;
	    vvii g(N);
        rep(j,M)
        {
            int x, y, w;
            cin >> x >> y >> w;
            cout<<x<<" "<<y<<" "<<w<<endl;
            x--, y--;
            w += L;
            g[x].push_back(ii(y, w));
		    g[y].push_back(ii(x, w)); // Sleppa þesari línu ef netið er stefnt.
        }
        cout << prim(g,s,v) <<  endl;
    }
	return 0;
}
