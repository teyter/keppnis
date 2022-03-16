#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vi v, p;
void dfs(vvi& g, int x)
{
	int i, f = 1;
	v[x] = 1;
	p.push_back(x);
	rep(i, g[x].size()) if (v[g[x][i]] == 0)
		dfs(g, g[x][i]), f = 0;
	p.pop_back();
	v[x] = 0;
}

// Fyrsta lína inntaksins eru tvær heiltölur, fjöldi nóða og fjöldi leggja.
// Síðan koma m línur sem svara til leggjalistans.
int main()
{
    int r,c,n,i,j,k,count;
    cin >> r >> c;
    int grid[r][c];
    int nodes[r][c];
    vvi g(r*c);
    count = 0;
    for (i = 0; i < r; i++)
    {
        string in;
        cin >> in;
        for (j = 0; j < c; j++)
        {
            grid[i][j] = (int)in[j] - 48;
            nodes[i][j] = count++;
        }
    }
    count = 0;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            k = grid[i][j];
            if (i-1 >= 0)
            {
                int north = nodes[i-1][j];
                int ngrid = grid[i-1][j];
                if ((k == 0 && ngrid == 0) || (k == 1 && ngrid == 1))
                    g[count].push_back(north);
            }
            if (j-1 >= 0)
            {
                int west = nodes[i][j-1];
                int wgrid = grid[i][j-1];
                if ((k == 0 && wgrid == 0) || (k == 1 && wgrid == 1))
                    g[count].push_back(west);
            }
            if (j+1 <= c)
            {
                int east = nodes[i][j+1];
                int egrid = grid[i][j+1];
                if ((k == 0 && egrid == 0) || (k == 1 && egrid == 1))
                    g[count].push_back(east);
            }
            if (i+1 <= r)
            {
                int south = nodes[i+1][j];
                int sgrid = grid[i+1][j];
                if ((k == 0 && sgrid == 0) || (k == 1 && sgrid == 1))
                    g[count].push_back(south);
            }
            count++;
        }
    }
	v = vi(r*c);
	rep(i, n) dfs(g, i);
	return 0;
}
