#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n, m;
vector<pair<int, int>> g[1005];
int dp[21][(1 << 20) + 1];

int rec(int node, int mask)
{
    if (mask == ((1 << n) - 1))
        return 0;

    if (dp[node][mask] != -1)
        return dp[node][mask];

    int ans = 1e18;
    for (auto v : g[node])
    {
        int nextNode = v.first;
        int weight = v.second;
        if (((mask >> nextNode) & 1) == 0)
            ans = min(ans, rec(nextNode, mask | (1 << nextNode)) + weight);
        }

    return dp[node][mask] = ans;
}

void solve()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    memset(dp, -1, sizeof(dp));

    int sh_path = 1e18;
    for (int i = 0; i < n; i++)
    {
        sh_path = min(sh_path, rec(i, (1 << i)));
    }
    cout << sh_path << endl;
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
