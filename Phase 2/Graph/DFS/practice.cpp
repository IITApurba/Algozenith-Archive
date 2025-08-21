#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;

int n, m;
vector<vector<int>> g;
vector<int> vis;

void dfs(int node)
{
    vis[node] = 1;

    for (auto v : g[node])
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

        // If undirected
        // g[b].push_back(a);
    }

    dfs(1);

    cout << endl;
    debug(g);
    debug(vis);

    for (int i = 1; i <= n; i++)
        cout << i << " " << vis[i] << endl;

    cout << endl;
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