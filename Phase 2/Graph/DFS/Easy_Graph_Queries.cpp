#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n, m;
vector<vector<int>> g;
vector<int> vis;

void dfs(int node, int comp_no)
{
    vis[node] = comp_no;

    for (auto &&v : g[node])
    {
        if (!vis[v])
            dfs(v, comp_no);
    }
}

void solve()
{
    int q;
    cin >> n >> m >> q;

    g.resize(n + 1);
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    /*
    1 X: Print the size of the connected components containing node X.
    2 X Y: Print ‘YES’ (without quotes) if node X and Y belong to the same connected component,
            else print ‘NO’ (without quotes).
    */

    int comp_no = 0;

    for (int i = 1; i <= n; i++)
    {
        comp_no++;

        if (!vis[i])
            dfs(i, comp_no);
    }

    vector<vector<int>> cc_comp;
    cc_comp.resize(comp_no + 1);

    for (int i = 1; i <= n; i++)
    {
        cc_comp[vis[i]].push_back(i);
    }

    while (q--)
    {
        int tt;
        cin >> tt;
        if (tt == 1)
        {
            int x;
            cin >> x;

            cout << cc_comp[vis[x]].size() << endl;
        }
        else
        {
            int x, y;
            cin >> x >> y;

            if (vis[x] == vis[y])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;

    while (t--)
        solve();

    return 0;
}