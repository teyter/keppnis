#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
    int n,m;
    cin >> n >> m;
	vvi g(n*m);
    int node;
    int grid[n][m];
    int nodes[n][m];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        string in;
        cin >> in;
        for (int j = 0; j < m; j++)
        {
            grid[i][j] = (int)in[j] - 48;
            nodes[i][j] = count++;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int k = grid[i][j];
            if (k > 0)
            {
                int north = i - (k*m);
                int west = j - k;
                int east = j + k;
                int south = i + (k*m);
                g[count].push_back(nodes[north][j]);
                g[count].push_back(nodes[i][west]);
                g[count].push_back(nodes[i][east]);
                g[count].push_back(nodes[south][j]);
            }
            else
            {
                g[count].push_back(k);
            }
            count++;
        }
    }
    for (int i = 0; i < n*m; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < g[i].size(); j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}
