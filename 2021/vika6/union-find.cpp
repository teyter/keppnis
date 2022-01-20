#include <iostream>
using namespace std;

#define MAXN 1000000
int p[MAXN];

int find(int x)
{
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void join(int x, int y)
{
    int rx = find(x), ry = find(y);
    if (rx == ry) return;
    if (p[rx] > p[ry]) 
    {
        p[ry] += p[rx];
        p[rx] = ry;
    }
    else 
    {
        p[rx] += p[ry];
        p[ry] = rx;
    }
}

int main() 
{
    int N,Q;
    cin >> N >> Q;
    char op[Q];
    int ab[Q][3];
    for (int i = 0; i < Q; i++)
        cin >> op[i] >>  ab[i][0] >> ab[i][1];
    for (int i = 0; i < MAXN; i++)
        p[i] = -1;

    for (int i = 0; i < Q; i++)
    {
        char ops = op[i];
        int a = ab[i][0];
        int b = ab[i][1];
        if (ops == '?')
        {
            if (find(a) == find(b))
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
        if (ops == '=')
        {
            join(a,b);
        }
    }
}
