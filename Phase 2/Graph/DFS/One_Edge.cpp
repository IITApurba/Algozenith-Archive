#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

#define int long long

vector<vector<int>> g;
vector<int> vis;

void dfs(int node, int comp_no)
{
    vis[node] = comp_no;

    for (auto v : g[node])
        if (!vis[v])
            dfs(v, comp_no);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    vis.assign(n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    int num_comp = 0;

    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            num_comp++;
            dfs(i, num_comp);
        }

    debug(vis);

    vector<vector<int>> components;
    components.resize(num_comp + 1);

    for (int i = 1; i <= n; i++)
    {
        cout << i << " : " << vis[i] << endl;
        components[vis[i]].push_back(i);
    }

    debug(components);

    vector<int> comp_size;
    for (int i = 1; i < components.size(); i++)
    {
        comp_size.push_back(components[i].size());
    }

    debug(comp_size);

    int sum = 0;
    for (int i = 0; i < comp_size.size(); i++)
    {
        sum += comp_size[i];
    }

    int ans = 0;

    for (int i = 0; i < comp_size.size(); i++)
    {
        sum -= comp_size[i];
        ans += comp_size[i] * sum;
    }

    cout << ans << endl;
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