#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;

vector<vector<ll>> g;

vector<ll> vis;

int cmp_size;

void dfs(int node)
{
    vis[node] = 1;
    cmp_size++;

    for (auto neigh : g[node])
        if (!vis[neigh])
            dfs(neigh);
}

void solve()
{
    int n, m;
    cin >> n >> m;

    g.resize(n + 1);
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a); // Incase of non-directed graph
    }

    vector<ll> cc_size;

    int cc_num = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cc_num++;
            cmp_size = 0;
            dfs(i);
            cc_size.push_back(cmp_size);
        }
    }


    // Number of (x,y) from different components
    ll ans = 0;
    ll sum = 0;
    for (auto v : cc_size)
    {
        ans += v * sum;
        sum += v;
    }
    cout << endl;


    debug(g);
    debug(vis);
    debug(cc_num);
    debug(cc_size);
    debug(ans);
    debug(sum);
    debug(cc_num);
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