#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vi v;
vi cs;
vi cs2;
void dfs(vvi& g, int x, vi& cs)
{
	int i;
    cs.push_back(x+1);
	v[x] = 1;
    for (i = 0; i < g[x].size(); i++)
    {
        if (v[g[x][i]] == 0)
        {
            dfs(g, g[x][i],cs);
        }
    }
}

int main()
{
	int i, j, n, m;
    int bstart, gstart;
	cin >> n >> m;
	cin >> bstart >> gstart;
    bstart--;gstart--;
	vvi g(n);
	rep(i, m)
	{
		int x, y, rusl, sorp;
		cin >> x >> y >> rusl >> sorp;
        x--;y--;
		g[x].push_back(y);
	}
	v = vi(n);
	dfs(g, bstart, cs);
	v = vi(n);
	dfs(g, gstart, cs2);
    vi ret;
    sort(cs.begin(),cs.end());
    sort(cs2.begin(),cs2.end());
    set_intersection(cs.begin(),cs.end(),cs2.begin(),cs2.end(),back_inserter(ret));
    if (ret.size() == 0) cout << "Thessi leikur verdur sennilega leidinlegur" << endl;
    else
    {
    rep(i,ret.size()) cout << ret[i] << " ";
    cout << endl;
    }
	return 0;
}
