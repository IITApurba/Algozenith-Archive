#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n;
vector<int> g[100005];
int arr[100005];

int dp[100005][2];

void indfs(int node, int par)
{
    dp[node][0] = arr[node];
    dp[node][1] = 0;
    for (auto v : g[node])
    {
        if (v == par)
            continue;
        indfs(v, node);
        dp[node][0] += max(dp[v][0], dp[v][1]);
        dp[node][1] += dp[v][0];
    }

    dp[node][0] = max(dp[node][0], dp[node][1]);
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    memset(dp, 0, sizeof(dp));
    indfs(1, 0);

    cout << dp[1][0] << "\n";
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