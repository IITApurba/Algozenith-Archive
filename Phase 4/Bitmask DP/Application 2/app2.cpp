#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n, m;
vector<int> g[1005];

int dp[21][1 << 20];

int ways(int node, int mask)
{
    if (mask == (1 << n) - 1)
        return node == n;

    if (dp[node][mask] != -1)
        return dp[node][mask];

    int ans = 0;

    for (int v : g[node])
    {
        if ((mask & (1 << (v - 1))))
            continue;

        ans += ways(v, mask | (1 << (v - 1)));
    }

    return dp[node][mask] = ans;
}

// TC: O((n+m) * 2^n)
// = O(2^n * n^2)

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

    cout << ways(1, 1) << endl;
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