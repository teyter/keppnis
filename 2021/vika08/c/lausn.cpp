#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define INF (1 << 30)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi floydwarshall(vvii& g)
{
	int i, j, k, n = g.size();
	vvi dp(n, vi(n, INF));
	rep(i, n) dp[i][i] = 0;
	rep(i, n) rep(j, g[i].size())
		dp[i][g[i][j].first] = min(g[i][j].second, dp[i][g[i][j].first]);
	rep(k, n) rep(i, n) rep(j, n)
	{
		if(dp[i][k] == INF || dp[k][j] == INF) continue;
		dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
	}
	rep(k, n) rep(i, n) rep(j, n)
	{
		if(dp[i][k] == INF || dp[k][j] == INF || dp[i][j] == INF) continue;
		if(dp[i][k] + dp[k][j] < dp[i][j]) dp[i][j] = -INF;
	}
	return dp;
}

int main()
{
    int i,j,n,m,q,u,v,w,start,end;
    int counter = 0;
    while (true)
    {
        cin >> n >> m >> q;
        if (n == 0 && m == 0 && q == 0) break;
        if (counter > 0) cout << endl; 
        counter = 1;
	    vvii g(n);
        rep(i, m)
        {
            cin >> u >> v >> w;
            g[u].push_back(ii(v, w));
        }
        vvi dp = floydwarshall(g);
        rep(i,q)
        {
            cin >> start >> end;
            if (dp[start][end] == INF)
            {
                cout << "Impossible" << endl;
            }
            else if (dp[start][end] == -INF)
            {
                cout << "-Infinity" << endl;
            }
            else cout << i << ": " << dp[start][end] << endl;
        }
    }
}
