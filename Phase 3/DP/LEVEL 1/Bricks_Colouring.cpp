#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

const int MOD = 1e9 + 7;

int n, m, k;
int dp[2020][2020];

int rec(int i, int k_left)
{
    // pruning
    if (k_left < 0)
        return 0;
    // base case
    if (i == n)
        return k_left == 0;

    if (dp[i][k_left] != -1)
        return dp[i][k_left];

    int ans = 0;

    ans += rec(i + 1, k_left) * 1;
    ans %= MOD;
    ans += rec(i + 1, k_left - 1) * (m - 1);
    ans %= MOD;

    return dp[i][k_left] = ans;
}

void solve()
{
    cin >> n >> m >> k;

    memset(dp, -1, sizeof(dp));

    int ans = m * rec(1, k) % MOD;

    cout << ans << endl;
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