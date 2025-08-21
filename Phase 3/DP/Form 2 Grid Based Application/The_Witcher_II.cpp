#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, m;
vector<vector<int>> arr;
vector<vector<int>> dp;

void solve()
{
    cin >> n >> m;
    arr.resize(n, vector<int>(m));
    dp.resize(n + 1, vector<int>(m + 1, 1e9));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    int ans = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (i == n - 1 && j == m - 1)
                dp[i][j] = max(1LL, 1 - arr[i][j]);
            else
                dp[i][j] = max(1LL, min(dp[i + 1][j], dp[i][j + 1]) - arr[i][j]);
        }
    }

    cout << dp[0][0] << endl;

    arr.clear();
    dp.clear();
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