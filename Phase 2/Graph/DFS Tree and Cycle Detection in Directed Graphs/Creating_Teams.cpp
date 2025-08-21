#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

vector<vector<int>> g;
vector<int> vis;
bool is_bipartite;

void dfs(int node, int col)
{
    vis[node] = col;

    for (auto &&v : g[node])
    {
        if (vis[v] == col)
        {
            is_bipartite = false;
        }
        else if (vis[v] == 0)
        {
            dfs(v, 3 - col);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    g.assign(n + 1, {});
    vis.assign(n + 1, 0);
    is_bipartite = true;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a); // Important for undirected graph
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i, 1);
    }

    cout << (is_bipartite ? "YES" : "NO") << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t; // uncomment if needed

    while (t--)
        solve();

    return 0;
}
