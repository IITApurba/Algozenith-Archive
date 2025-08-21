#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

using ii = pair<int, int>;
#define F first
#define S second
#define mp make_pair

// class prioritize
// {
// public:
//     bool operator()(ii &p1, ii &p2)
//     {
//         return p1.S > p2.S;
//     }
// };

#define int long long
int n, m;
vector<ii> g[100100];

int dis[100100];
int vis[100100];

void dijkstra(int sc)
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e18;
        vis[i] = 0;
    }

    dis[sc] = 0;

    priority_queue<ii> pq;

    pq.push(mp(-0, sc));

    while (!pq.empty())
    {
        ii fs = pq.top();
        pq.pop();

        if (vis[fs.S])
            continue;
        vis[fs.S] = 1;

        for (auto v : g[fs.S])
        {
            int neigh = v.F;
            int wt = v.S;

            if (dis[neigh] > dis[fs.S] + wt)
            {
                dis[neigh] = dis[fs.S] + wt;
                pq.push(mp(-dis[neigh], neigh));
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    dijkstra(1);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}