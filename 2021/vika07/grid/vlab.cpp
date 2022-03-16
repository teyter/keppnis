#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
    vvi g;
    vi p = {1,2,3};
    vi q = {4,5,6};
    vi r = {7,8,9};
    g.push_back(p);
    g.push_back(q);
    g.push_back(r);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}
