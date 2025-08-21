#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    char a[n][n];
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    dp[0][0] = (a[0][0] == '.' ? 1 : 0);

    for (int i = 1; i < n; i++)
        dp[i][0] = (a[i][0] == '*' ? 0 : dp[i - 1][0]);

    for (int j = 1; j < n; j++)
        dp[0][j] = (a[0][j] == '*' ? 0 : dp[0][j - 1]);

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (a[i][j] == '*')
            {
                dp[i][j] = 0;
                continue;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j] % mod + dp[i][j - 1] % mod) % mod;
            }
        }
    }

    cout << dp[n - 1][n - 1] << endl;
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