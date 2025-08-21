#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n, m;
vector<vector<int>> g;
vector<int> vis;

bool dfs(int node, int col)
{
    vis[node] = col;

    for (auto v : g[node])
    {
        if (!vis[v])
        {
            if (!dfs(v, 3 - col))
                return false;
        }
        else if (vis[v] == vis[node])
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    cin >> n >> m;

    g.assign(n + 1, {});
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (!dfs(i, 1))
            {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << vis[i] << " ";
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
