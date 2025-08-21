#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

const int MOD = 1e9 + 7;

int n, m;
vector<int> arr;
int dp[101][101]; // dp[i][prev], where prev is arr[i-1]

int rec(int i, int prev)
{
    if (i == n)
        return 1;

    if (dp[i][prev] != -1)
        return dp[i][prev];

    int ans = 0;

    cout << "level : " << i << endl;

    if (arr[i] != 0)
    {
        if (i == 0 || abs(arr[i] - prev) <= 1)
        {
            ans = rec(i + 1, arr[i]) % MOD;
        }
    }
    else
    {
        for (int val = 1; val <= m; val++)
        {
            if (i == 0 || abs(val - prev) <= 1)
            {
                ans = (ans + rec(i + 1, val)) % MOD;
            }
        }
    }

    return dp[i][prev] = ans;
}

// void solve()
// {
//     cin >> n >> m;
//     arr.resize(n);
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     memset(dp, -1, sizeof(dp));

//     int ans = rec(0, 0);

//     cout << ans << '\n';
// }

void solve()
{
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<int>> dp(n, vector<int>(m + 2, 0));

    if (arr[0] != 0)
    {
        dp[0][arr[0]] = 1;
    }
    else
    {
        for (int val = 1; val <= m; val++)
            dp[0][val] = 1;
    }

    // Fill the dp table
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            int val = arr[i];
            dp[i][val] = (dp[i - 1][val - 1] + dp[i - 1][val] + dp[i - 1][val + 1]) % MOD;
        }
        else
        {
            for (int val = 1; val <= m; val++)
            {
                dp[i][val] = (dp[i - 1][val - 1] + dp[i - 1][val] + dp[i - 1][val + 1]) % MOD;
            }
        }
    }

    // Answer is sum of all dp[n-1][val]
    int ans = 0;
    for (int val = 1; val <= m; val++)
        ans = (ans + dp[n - 1][val]) % MOD;

    cout << ans << '\n';
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
