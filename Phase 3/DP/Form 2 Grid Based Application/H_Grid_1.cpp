#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n, m;
char arr[1005][1005];
int dp[1005][1005];

int mod = 1e9 + 7;

void solve()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    // number of ways to reach cell (i, j) = number of ways to reach cell (i-1, j) + number of ways to reach cell (i, j-1)
    // if cell (i, j) is not blocked

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '#')
            {
                dp[i][j] = 0;
            }
            else
            {
                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else if (i == 0)
                    dp[i][j] = dp[i][j - 1] % mod;
                else if (j == 0)
                    dp[i][j] = dp[i - 1][j] % mod;
                else
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            }
        }
    }


    cout << dp[n - 1][m - 1] << endl;
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