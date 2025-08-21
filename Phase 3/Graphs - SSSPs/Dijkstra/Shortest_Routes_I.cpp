#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

using ii = pair<int, int>;

int n, m;
vector<vector<ii>> g;
vector<int> dis, parent, path, vis;

void bfs(int sc)
{
    dis[sc] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> PQ;
    PQ.push({0, sc});

    while (!PQ.empty())
    {
        auto [d, u] = PQ.top();
        PQ.pop();

        if (vis[u] == 1)
            continue;

        vis[u] = 1;

        for (auto [v, w] : g[u])
        {
            if (dis[v] > dis[u] + w)
                dis[v] = dis[u] + w;

            PQ.push({dis[v], v});
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    dis.assign(n + 1, 1e18);
    parent.assign(n + 1, -1);
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    bfs(1);

    for (auto i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }

    cout << endl;
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