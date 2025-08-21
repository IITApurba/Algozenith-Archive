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
    dp.resize(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i - 1][j - 1] == 1)
            {

                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                ans = max(ans, dp[i][j]);
            }
        }
    }

    cout << ans * ans << endl;
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