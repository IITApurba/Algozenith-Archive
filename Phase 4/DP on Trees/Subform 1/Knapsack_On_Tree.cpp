#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

const int MAXN = 5005;
const int INF = -1e18;

int n;
vector<int> val;
vector<int> g[MAXN];

vector<vector<int>> dp[MAXN];
int sz[MAXN];

void dfs(int u, int par)
{
    dp[u] = vector<vector<int>>(2, vector<int>(2, INF));
    dp[u][0][0] = 0;
    dp[u][1][1] = val[u];
    sz[u] = 1;

    for (int v : g[u])
    {
        if (v == par)
            continue;

        dfs(v, u);

        int maxK = sz[u] + sz[v];
        vector<vector<int>> new_dp(2, vector<int>(maxK + 1, INF));

        for (int i = 0; i <= sz[u]; ++i)
        {
            for (int j = 0; j <= sz[v]; ++j)
            {
                new_dp[0][i + j] = max(new_dp[0][i + j], dp[u][0][i] + max(dp[v][0][j], dp[v][1][j]));

                if (j + i <= maxK)
                    new_dp[1][i + j] = max(new_dp[1][i + j], dp[u][1][i] + dp[v][0][j]);
            }
        }

        sz[u] += sz[v];

        dp[u][0] = new_dp[0];
        dp[u][1] = new_dp[1];
    }
}

void solve()
{
    cin >> n;
    val.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> val[i];

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);

    for (int k = 1; k <= n; ++k)
    {
        int ans = INF;
        if (k < dp[1][0].size())
            ans = max(ans, dp[1][0][k]);
        if (k < dp[1][1].size())
            ans = max(ans, dp[1][1][k]);

        if (ans == INF || ans < -1e10)
            cout << "F ";
        else
            cout << ans << " ";
    }
    cout << "\n";

    //clear
    for (int i = 1; i <= n; ++i)
    {
        g[i].clear();
        dp[i].clear();
        sz[i] = 0;
    }

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
