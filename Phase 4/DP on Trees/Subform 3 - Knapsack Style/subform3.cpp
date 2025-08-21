#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n, k;
vector<int> g[101];

int arr[101];
int sz[101];
int dp[101][2][101];

void dfs(int node, int pp)
{

    for (int i = 0; i <= k; i++)
    {
        dp[node][1][i] = (i == 1 ? arr[node] : -1e18);
        dp[node][0][i] = i == 0 ? 0 : -1e18;
    }

    for (auto v : g[node])
    {
        dfs(v, node);

        for (int a = sz[node]; a >= 0; a--)
        {
            for (int b = sz[v]; b >= 0; b--)
            {

                dp[node][0][a + b] = max(dp[node][0][a + b], dp[node][0][a] + max(dp[v][0][b], dp[v][1][b]));
                dp[node][1][a + b] = max(dp[node][1][a + b], dp[node][1][a] + dp[v][0][b]);
            }
        }

        sz[node] += sz[v];
    }
}

void solve()
{
    cin >> n >> k;

    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0);

    cout << max(dp[1][0][k], dp[1][1][k]) << "\n";
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