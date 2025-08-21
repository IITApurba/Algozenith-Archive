#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;
vector<vector<int>> g;
vector<int> vis;

void dfs(int node, int comp_no)
{
    vis[node] = comp_no;
    for (int child : g[node])
    {
        if (!vis[child])
            dfs(child, comp_no);
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
        g[b].push_back(a);
    }

    int comp_no = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            comp_no++;
            dfs(i, comp_no);
        }
    }

    cout << comp_no - 1 << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}