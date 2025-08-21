#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

const int mod = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> prefix_sum(n + 1, vector<int>(m + 1, 0));

    // Input and normalize negative values
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
            arr[i][j] = (arr[i][j] % mod + mod) % mod; // normalize negative
        }

    // Build prefix sum matrix
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            prefix_sum[i][j] = (
                arr[i][j]
                + prefix_sum[i - 1][j]
                + prefix_sum[i][j - 1]
                - prefix_sum[i - 1][j - 1]
                + mod * 2) % mod;

    int q;
    cin >> q;
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int ans = (
            prefix_sum[x2][y2]
            - prefix_sum[x1 - 1][y2]
            - prefix_sum[x2][y1 - 1]
            + prefix_sum[x1 - 1][y1 - 1]
            + 2 * mod) % mod;

        cout << ans << '\n';
    }
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
