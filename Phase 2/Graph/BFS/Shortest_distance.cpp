#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;

int n, m;
vector<vector<int>> g;
vector<int> vis;
vector<int> dis;

void bfs(int sc_node)
{
    queue<int> q;
    vis[sc_node] = 1;
    dis[sc_node] = 0;
    q.push(sc_node);

    while (!q.empty())
    {
        int node = q.front();
        // SSSP
        // Single Source Shortest Path
        q.pop();
        for (auto v : g[node])
        {
            if (!vis[v])
            {
                vis[v] = 1;
                dis[v] = dis[node] + 1;
                q.push(v);
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    vis.assign(n + 1, 0);
    dis.assign(n + 1, 1000);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs(1);

    for (int i = 1; i <= n; i++)
        cout << i << ": " << vis[i] << "," << dis[i] << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}