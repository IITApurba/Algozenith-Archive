#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n, m;

vector<vector<int>> g;
vector<int> vis;

void dfs(int node)
{
    vis[node] = 1;

    for (auto &&v : g[node])
    {
        if (!vis[v])
            dfs(v);
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a); // Undirected Graph
    }

    dfs(1);

    // COMPONENT SIZE
    // NUMBER OF COMPONENTS
    // SAAB KUCK HO SAKTA HAA JO BHI HUM CHAHIYEE!!!
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