#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
    int n = 20;
    int m = 39;
    int i,j;
    vvi g = {
        {2,8},
        {0,2,5},
        {0,10},
        {3},
        {0,5,8},
        {7,13},
        {6},
        {4,19},
        {11},
        {5,8,10,13},
        {6,9,11,14},
        {8},
        {8,13,16},
        {9,12,14,17},
        {6,12},
        {15},
        {12,17},
        {13,16,18},
        {14,17,19},
        {19}
    };
/*
    for (i = 0; i < n*m; i++)
    {
        cout << i << ": ";
        for (j = 0; j < g[i].size(); j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
*/
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
