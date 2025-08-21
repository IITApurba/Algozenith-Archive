#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

double dp[3001][3001]; // dp[i][j] = prob of getting j heads among first i coins
double p[3001];
int n;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            // Get tail
            dp[i][j] += dp[i - 1][j] * (1 - p[i]);

            // Get head
            if (j > 0)
                dp[i][j] += dp[i - 1][j - 1] * p[i];
        }
    }

    int minHeads = (n / 2) + 1;
    double ans = 0;
    for (int heads = minHeads; heads <= n; heads++)
        ans += dp[n][heads];

    cout << fixed << setprecision(10) << ans << "\n";
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
