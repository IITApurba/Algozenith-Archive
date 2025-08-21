#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> g;
vector<int> vis, color;
vector<pair<int, int>> edges;
int n, m;

void dfs(int node, int colour)
{
    vis[node] = 1;
    color[node] = colour;

    for (auto child : g[node])
    {
        if (!vis[child])
        {
            dfs(child, 3 - colour);
        }
        else
        {
            if (color[child] == color[node])
            {
                cout << "NO" << endl;
                exit(0);
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    vis.assign(n + 1, 0);
    color.assign(n + 1, 0); // Fix: Initialize the color array

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.push_back({u, v});
    }

    for (int i = 1; i <= n; i++)
    { // Fix: Ensure full traversal
        if (!vis[i])
        {
            dfs(i, 1);
        }
    }

    cout << "YES" << endl;

    for (auto u : edges){
        if (color[u.first] == 1)
            cout << 0;
        else
            cout << 1;
    }
    cout << endl;

    vis.clear();
    color.clear();
    g.clear();
    edges.clear();
    
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
