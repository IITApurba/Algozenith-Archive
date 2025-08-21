#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n, m;
vector<int> g[1005];
int dp[21][(1 << 20) + 1];

int rec(int node, int mask)
{
    if (dp[node][mask] != -1)
        return dp[node][mask];

    int ans = (__builtin_popcount(mask) >= 2) ? 1 : 0;

    for (auto v : g[node])
    {
        if (((mask >> v) & 1) == 0)
        {
            ans += rec(v, mask | (1 << v));
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
        g[v].push_back(u); // Assuming undirected graph
    }

    memset(dp, -1, sizeof(dp));

    int simple_paths = 0;
    for (int i = 0; i < n; i++)
        simple_paths += rec(i, (1 << i));
    cout << simple_paths / 2 << endl;
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