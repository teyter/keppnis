#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vi v;
int target;
bool b;

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

void dfs(vvi& g, int x)
{
    //cout << "x: " << x << "\ttarget: " << target << endl;
    if (x == target) 
    {
        b = 1;
    }
	int i;
	v[x] = 1;
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
    /*
	v = vi(r*c);
    int r1,c1,r2,c2,start;
    r1 = 2;
    c1 = 3;
    r2 = 8;
    c2 = 16;
    start = c1+((r1-1)*c);
    target = c2+((r2-1)*c);
    cout << start << " " << target << endl;
    //printvv(g);
    */
    cin >> n;
    //cout << n << endl;
	v = vi(r*c);
    int r1,c1,r2,c2,start;
    for (i = 0; i < n; i++)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        start = c1+((r1-1)*c);
        target = c2+((r2-1)*c);
        //cout << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
        start--;target--;r1--;c1--;r2--;c2--;
        b = 0;
        dfs(g,start);
        if (grid[r1][c1] == 0 && b)
        {
            cout << "binary" << endl;
        }
        else if (grid[r1][c1] == 1 && b)
        {
            cout << "decimal" << endl;
        }
        else
            cout << "neither" << endl;

    }
}
