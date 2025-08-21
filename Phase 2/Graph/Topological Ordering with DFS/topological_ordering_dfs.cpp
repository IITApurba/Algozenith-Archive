#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;

int n, m;

vector<vector<int>> g;
vector<int> vis;

vector<int> topo;

void dfs(int node)
{
    vis[node] = 1;
    
    for (int v : g[node])
        if (!vis[v])
            dfs(v);

    topo.push_back(node);
}

void solve()
{
    cin >> n >> m;

    g.resize(n + 1);
    vis.resize(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i);

    reverse(topo.begin(), topo.end());

    cout << "Topological Order: ";
    for (int i : topo)
        cout << i << " ";

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