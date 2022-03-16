#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
    int n,m,i,j;
    cin >> n >> m;
	vvi g(n*m);
    int grid[n][m];
    int nodes[n][m];
    int count = 0;
    for (i = 0; i < n; i++)
    {
        string in;
        cin >> in;
        for (j = 0; j < m; j++)
        {
            grid[i][j] = (int)in[j] - 48;
            nodes[i][j] = count++;
        }
    }
    count = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            int k = grid[i][j];
            if (k > 0)
            {
                int north = nodes[i][j] - (k*m);
                int west = nodes[i][j] - k;
                int east = nodes[i][j] + k;
                int south = nodes[i][j] + (k*m);
                if (i-k >= 0) g[count].push_back(north);
                if (j-k >= 0) g[count].push_back(west);
                if (j+k < m) g[count].push_back(east);
                if (i+k < n) g[count].push_back(south);
            }
            else
            {
                g[count].push_back(nodes[i][j]);
            }
            count++;
        }
    }
    n *= m;

    // bfs
	vi d(n, -1);
	queue<int> q;
	q.push(0);
	d[0] = 0;
	while (q.size() > 0)
	{
		int x = q.front();
		q.pop();
		rep(i, g[x].size()) if (d[g[x][i]] == -1)
		{
			q.push(g[x][i]);
			d[g[x][i]] = d[x] + 1;
		}
	}
    cout << d[n-1] << endl;
	return 0;
}
