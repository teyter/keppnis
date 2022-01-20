#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<vi> vvi;

vi v;
vc t;
int gold = 0;
void dfs(vvi& g, int x)
{
	v[x] = 1;
    if (t[x] == 't')
    {
        return;
    }
    else if (t[x] == 'g')
    {
        gold++;
        return;
    }
    else if (t[x] == 'G')
    {
        gold++;
    }

	int i;
    for (i = 0; i < g[x].size(); i++)
    {
        if (v[g[x][i]] == 0)
        {
            dfs(g, g[x][i]);
        }
    }
}

int main()
{
    int n,m,i,j;
    cin >> m >> n;
	vvi g(n*m);
    char grid[n][m];
    int nodes[n][m];
    int count = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            nodes[i][j] = count++;
        }
    }
    count = 0;
    int p;
    t = vc(n*m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            char k = grid[i][j];
            if (k == '#')
            {
                g[count].push_back(nodes[i][j]);
                t[count] = '#';
            }
            else
            {
                int north = grid[i-1][j];
                int west = grid[i][j-1];
                int east = grid[i][j+1];
                int south = grid[i+1][j];
                if (grid[i-1][j] != '#') g[count].push_back(nodes[i-1][j]);
                if (grid[i][j-1] != '#') g[count].push_back(nodes[i][j-1]);
                if (grid[i][j+1] != '#') g[count].push_back(nodes[i][j+1]);
                if (grid[i+1][j] != '#') g[count].push_back(nodes[i+1][j]);

                if (k == '.')
                {
                    if (north == 'T' || west == 'T' || east == 'T' || south == 'T') 
                    {
                        t[count] = 't';
                    }
                    else t[count] = '.';
                }
                if (k == 'G') 
                {
                    if (north == 'T' || west == 'T' || east == 'T' || south == 'T') 
                    {
                        t[count] = 'g';
                    }
                    else t[count] = 'G';
                }
                if (k == 'T') t[count] = 'T';
                if (k == 'P') 
                {
                    p = nodes[i][j];
                    t[count] = 'P';
                }
            }
            count++;
        }
    }
	v = vi(n*m);
	dfs(g, p);
    cout << gold << endl;
	return 0;
}
