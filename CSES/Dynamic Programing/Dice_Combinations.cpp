#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n;

int mod = 1e9 + 7;
int moves[] = {1, 2, 3, 4, 5, 6};

int dp[1001000];

int rec(int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    if (dp[n] != -1)
        return dp[n] % mod;

    int ans = 0;

    for (int i = 0; i < 6; i++)
    {
        ans = (ans + rec(n - moves[i]) % mod) % mod;
    }

    return dp[n] = ans;
}

void solve()
{
    cin >> n;

    memset(dp, -1, sizeof(dp));

    cout << rec(n) << endl;
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