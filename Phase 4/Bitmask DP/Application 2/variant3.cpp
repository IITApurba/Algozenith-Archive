#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n, m;
vector<int> g[1005];

int dp[21][(1 << 20) + 1];

int rec(int node, int mask, int st_node)
{
    if (mask == (1 << n) - 1)
    {
        for (auto v : g[node])
        {
            if (v == st_node)
                return 1; // Valid cycle if there's an edge back to start
        }
        return 0;
    }

    if (dp[node][mask] != -1)
        return dp[node][mask];

    int ans = 0;
    for (auto v : g[node])
    {
        if (((mask >> v) & 1) == 0)
        {
            ans += rec(v, mask | (1 << v), st_node);
        }
    }
    return dp[node][mask] = ans;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    memset(dp, -1, sizeof(dp));

    int no_of_cycles = 0;
    for (int i = 0; i < n; i++)
    {
        no_of_cycles += rec(i, (1 << i), i);
    }
    cout << no_of_cycles << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}