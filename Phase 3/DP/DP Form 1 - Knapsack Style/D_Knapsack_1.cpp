#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n, W;
int wt[100005];
int v[105];
int dp[105][100005];

int rec(int i, int w)
{
    if (i == n || w == 0)
        return 0;

    if (dp[i][w] != -1)
        return dp[i][w];

    // compute
    int ans = rec(i + 1, w);

    if (wt[i] <= w)
        ans = max(ans, v[i] + rec(i + 1, w - wt[i]));

    return dp[i][w] = ans;
}

void solve()
{
    cin >> n >> W;

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++)
        cin >> wt[i] >> v[i];

    int ans = rec(0, W);

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