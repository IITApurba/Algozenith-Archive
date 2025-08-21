#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n;

vector<int> g[100100];
int dep[100100];
int par[100100];
int subtreeSz[100100];

void dfs(int node, int parent, int depth)
{
    dep[node] = depth;
    par[node] = parent;

    subtreeSz[node] = 1;

    for (auto v : g[node])
    {
        if (v != parent)
        {
            dfs(v, node, depth + 1);
            subtreeSz[node] += subtreeSz[v];
        }
    }
}

void solve()
{
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0, 0);

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        ans += subtreeSz[i] * (n - subtreeSz[i]);
    }

    cout << ans << endl;
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