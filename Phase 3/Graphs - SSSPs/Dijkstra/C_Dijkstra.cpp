#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

using ii = pair<int, int>;
#define F first
#define S second
#define mp make_pair

class prioritize
{
public:
    bool operator()(ii &p1, ii &p2)
    {
        return p1.S > p2.S;
    }
};

int n, m;
vector<ii> g[100100];
vector<int> dis(100100, 1e18);
vector<int> vis(100100, 0);
vector<int> parent(100100, -1);
vector<int> path;

void dijkstra(int sc)
{
    dis[sc] = 0;

    priority_queue<ii, vector<ii>, prioritize> pq;
    pq.push(mp(sc, 0));

    while (!pq.empty())
    {
        ii fs = pq.top();
        pq.pop();
        if (vis[fs.F])
            continue;
        vis[fs.F] = 1;

        for (auto v : g[fs.F])
        {
            int neigh = v.F;
            int wt = v.S;

            if (dis[neigh] > dis[fs.F] + wt)
            {
                dis[neigh] = dis[fs.F] + wt;
                parent[neigh] = fs.F;
                pq.push(mp(neigh, dis[neigh]));
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(mp(v, w));
        g[v].push_back(mp(u, w));
    }

    dijkstra(1);

    // print shortest path from 1 to n is exists else print -1
    if (dis[n] == 1e18)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        // cout << dis[n] << endl;
        int curr = n;
        while (curr != -1)
        {
            path.push_back(curr);
            curr = parent[curr];
        }
        reverse(path.begin(), path.end());
        for (auto x : path)
            cout << x << " ";
        cout << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}