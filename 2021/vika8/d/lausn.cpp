#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int tsort(vvi& g, vi& t)
{
	int i, j, r = 1, n = g.size();
	vi d(n, 0);
	t = vi();
	int q[n], qe = 0, qs = 0;
	rep(i, n) rep(j, g[i].size()) d[g[i][j]]++;
	rep(i, n) if (d[i] == 0) q[qe++] = i;
	while (qe != qs)
	{
		if (qe - qs > 1) r = 2;
		int k = q[qs++];
		t.push_back(k);
		rep(i, g[k].size()) if (--d[g[k][i]] == 0) q[qe++] = g[k][i];
	}
	return t.size() != n ? 0 : r;
}

int main()
{
	int i, j, n, m, c = 0;
	cin >> n >> m;
	vi t;
	vvi g(n);
	rep(i, m)
	{
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
	}
	int r = tsort(g, t);
	if (r == 2) cout << "back to the lab" << endl;
    else 
    {
        rep(i, n) cout << t[i] << " ";
        cout << endl;
    }
	return 0;
}
