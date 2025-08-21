#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;

vector<vector<ll>> g;

vector<ll> vis;
vector<ll> col;

bool is_bipartite = 1;

void dfs(int node, int cur_col)
{
    vis[node] = 1;
    col[node] = cur_col;

    for (auto neigh : g[node])
        if (!vis[neigh])
            dfs(neigh, 3 - cur_col);
        else if (col[neigh] == col[node])
            is_bipartite = 0;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    g.resize(n + 1);
    vis.assign(n + 1, 0);
    col.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    is_bipartite = 1;

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, 1);

    if (is_bipartite)
        cout << "POSSIBLE" << endl;
    else{
        cout << "NOT POSSIBLE" << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
        cout << i << " " << col[i] << endl;
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