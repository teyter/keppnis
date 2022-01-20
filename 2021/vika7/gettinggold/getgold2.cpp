#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;

vi v;
vi history;
int gold = 0;
void printv(vvi& g)
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
void dfs(vvi& g, int x, vc& t)
{
    cout << "node: " << x << "\tgold: " << gold << "\ttype: " << t[x] << endl;
    printv(g);
	int i;
	v[x] = 1;
    history.push_back(x);
    for (i = 0; i < g[x].size(); i++)
    {
        if (v[g[x][i]] == 0)
        {
            if (t[x] == 't')
            {
                g[x].clear();
                g[x].push_back(x);
                dfs(g, history.back(), t);
            }
            else if (t[x] == 'g')
            {
                gold++;
                g[x].clear();
                g[x].push_back(x);
                dfs(g, history.back(), t);
            }
            if (t[x] == 'G')
            {
                gold++;
            }
            dfs(g, g[x][i], t);
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
    vvc t(n*m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            char k = grid[i][j];
            if (k == '#')
            {
                g[count].push_back(nodes[i][j]);
                traps[count] = '#';
            }
            else
            {
                int north = grid[i-1][j];
                int west = grid[i][j-1];
                int east = grid[i][j+1];
                int south = grid[i+1][j];
                if (grid[i-1][j] != '#') 
                {
                    g[count].push_back(nodes[i-1][j]);
                }
                if (grid[i][j-1] != '#') 
                {
                    g[count].push_back(nodes[i][j-1]);
                }
                if (grid[i][j+1] != '#') 
                {
                    g[count].push_back(nodes[i][j+1]);
                }
                if (grid[i+1][j] != '#') 
                {
                    g[count].push_back(nodes[i+1][j]);
                }

                if (k == '.')
                {
                    if (north == 'T' || west == 'T' || east == 'T' || south == 'T') 
                    {
                        traps[count] = 't';
                    }
                    else traps[count] = '.';
                }
                if (k == 'G') 
                {
                    if (north == 'T' || west == 'T' || east == 'T' || south == 'T') 
                    {
                        traps[count] = 'g';
                    }
                    else traps[count] = 'G';
                }
                if (k == 'T') traps[count] = 'T';
                if (k == 'P') 
                {
                    p = nodes[i][j];
                    traps[count] = 'P';
                }
            }
            count++;
        }
    }
	v = vi(n*m);
	dfs(g, p, traps);
    cout << gold << endl;
	return 0;
}
