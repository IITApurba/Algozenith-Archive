#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n, m;
vector<int> g[21];
int dp[21][1 << 20];

// Recursively count simple cycles starting from st_node,
// current at node `node`, having visited nodes represented by `mask`.
int rec(int node, int mask, int st_node)
{
    if (dp[node][mask] != -1)
        return dp[node][mask];

    int ans = 0;
    for (auto v : g[node])
    {
        // If v is the start node, and mask has at least 3 nodes, we found a cycle
        if (v == st_node && __builtin_popcount(mask) >= 3)
        {
            ans += 1;
        }
        // Otherwise, if v not visited and v > st_node (to avoid duplicates)
        else if (((mask >> v) & 1) == 0 && v > st_node)
        {
            ans += rec(v, mask | (1 << v), st_node);
        }
    }

    return dp[node][mask] = ans;
}

void solve()
{
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        g[i].clear();
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // Convert to zero-based indexing internally
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(dp, -1, sizeof(dp));

    int ans = 0;

    // Start from each node and count cycles starting from it
    for (int i = 0; i < n; i++)
    {
        ans += rec(i, (1 << i), i);
    }

    // Each cycle is counted exactly once because of the v > st_node condition
    cout << ans / 2 << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // If multiple test cases, uncomment below
    // cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
