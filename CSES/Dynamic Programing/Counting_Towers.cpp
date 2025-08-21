#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

const int MOD = 1e9 + 7;
int dp[1000100];

int rec(int n)
{

    if (n == 1)
        return dp[1] = 2;
    if (n == 2)
        return dp[2] = 8;

    if (dp[n] != -1)
        return dp[n];

    int ans = (6LL * rec(n - 1) % MOD - 7LL * rec(n - 2) % MOD + MOD) % MOD;
    return dp[n] = ans;
}

void solve()
{
    int tt;
    cin >> tt;

    while (tt--)
    {
        int n;
        cin >> n;
        cout << rec(n) << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof(dp));

    solve();

    return 0;
}
