#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<ll> vi;

ll prim(vvii& g, vi& s, vi& v)
{
    ////cout << g.size() << endl;
    ll i, j, x, y, w, n = g.size();
    ll r = 0;
    priority_queue<iii> q;
    for (i = 0; i < s.size(); i++)
    {
        for (j = 0; j < g[s[i]].size(); j++)
        {
            //cout << g[i].size() << endl;
            q.push(iii(-g[s[i]][j].second,ii(g[s[i]][j].first,s[i])));
            //cout <<g[s[i]][j].second << endl;
        }
    }
    while (q.size() > 0)
    {
        iii p = q.top(); 
        q.pop();
        w = -p.first;
        x = p.second.first;
        y = p.second.second;
        if (v[x] == 1) continue;
        r += w;
        v[x] = 1;
        for (i = 0; i < g[x].size(); i++)
        {
                q.push(iii(-g[x][i].second, ii(g[x][i].first, x)));
        }
    }
    return r;
}
void printvv(vvii& g)
{
    for (int i = 0; i < g.size(); i++)
    {
        cout << "size: " << g[i].size() <<" "<< i+1 << ": ";

        for (int j = 0; j < g[i].size(); j++)
        {
            cout<< g[i][j].first+1 <<" "<< g[i][j].second+1 <<" ";
        }
        cout << endl;
    }
}
int main()
{
    ll n;
    ll i, j;
    cin >> n;
    //cout<<n<<endl;
    rep(i,n)
    {
        ll N, M, L, S;
        cin >> N >> M >> L >> S;
        //cout<<N<<" "<<M<<" "<<L<<" "<<S<<endl;
        vi s;
        vi v(N);
        rep(j,S)
        {
            ll station;
            cin >> station;
        //cout << station << " ";
            station--;
            v[station] = 1;
            s.push_back(station);
        }
        //cout << endl;
        vvii g(N);
        rep(j,M)
        {
            ll x, y, w;
            cin >> x >> y >> w;
            cout<<x<<" "<<y<<" "<<w<<endl;
            x--, y--;
            w += L;
            g[x].push_back(ii(y, w));
            g[y].push_back(ii(x, w)); // Sleppa þesari línu ef netið er stefnt.
        }
        cout << prim(g,s,v) <<  endl;
        //printvv(g);
    }
    return 0;
}

