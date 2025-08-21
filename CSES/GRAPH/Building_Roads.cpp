#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n, m;

vector<vector<int>> g;
vector<int> vis;
vector<int> ans;

void dfs(int node, int comp_no)
{
    vis[node] = comp_no;

    for (auto v : g[node])
    {
        if (!vis[v])
            dfs(v, comp_no);
    }
}

void solve()
{
    cin >> n >> m;

    g.clear();
    g.resize(n + 1);
    vis.assign(n + 1, 0);
    ans.clear();

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
            ans.push_back(i);
            comp_no++;
            dfs(i, comp_no);
        }
    }

    cout << comp_no - 1 << "\n";

    for (int i = 0; i + 1 < ans.size(); i++)
    {
        cout << ans[i] << " " << ans[i + 1] << "\n";
    }
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
