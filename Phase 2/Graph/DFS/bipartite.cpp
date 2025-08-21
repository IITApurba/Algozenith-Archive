#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;

int n, m;
vector<vector<int>> g;
vector<int> vis;

bool is_bipartite = true;

void dfs(int node, int color)
{
    vis[node] = color;

    for (auto v : g[node])
        if (!vis[v])
            dfs(v, 3 - color);
        else if (vis[v] == vis[node])
            is_bipartite = 0;
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
        g[b].push_back(a);
    }

    // ODD Cycle don't confuse with ODD Components

    int num_comp = 0;

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, 1);

    if (is_bipartite)
        cout << "Yes Bipartite" << endl;
    else
        cout << "Not Bipartite" << endl;

    for (int i = 1; i <= n; i++)
        cout << i << " : " << vis[i] << endl;

    // Number of possiblities of Bipartite
    // Section A and B
    //  2^(number of Components)
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