#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

// Fyrsta lína inntaksins eru tvær heiltölur, fjöldi hnúta og fjöldi leggja.
// Síðan koma m línur sem svara til leggjalistans.
int main()
{
    int i,j,n,m,q,s,u,v,w,query;
    while (true)
    {
        cin >> n >> m >> q >> s;
        //cout<<n<<" "<<m<<" "<<q<<" "<<s<<endl;
        if (n == 0 && m == 0 && q == 0 && s == 0) break;
	    vvii g(n);
        rep(i, m)
        {
            cin >> u >> v >> w;
            //cout<<u<<" "<<v<<" "<<w<<endl;
            g[u].push_back(ii(v, w));
        }
        rep(i,q)
        {
            cin >> query;
            int ans = path(s,query);
            if (ans > -1)
            {
                cout << ans << endl;
            }
            else cout << "Impossible" << endl;
        }
        cout << endl;
    }
}
