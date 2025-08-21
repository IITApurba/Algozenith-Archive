#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int arr[1005][1005];
int dp[1005][1005];
int n, m;

void solve()
{
    cin >> n >> m;

    // arr[i][j] -> rewards if we take a path from that cell
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    // find the max reward path from (0, 0) to (n-1, m-1)
    // number of ways to reach cell (i, j) = number of ways to reach cell (i-1, j) + number of ways to reach cell (i, j-1)
    // there is no blockage in the path, so we can take any path
    // dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + arr[i][j]

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = arr[i][j];
            else if (i == 0)
                dp[i][j] = dp[i][j - 1] + arr[i][j];
            else if (j == 0)
                dp[i][j] = dp[i - 1][j] + arr[i][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
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
    cin >> t;

    while (t--)
        solve();

    return 0;
}