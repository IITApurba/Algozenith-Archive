#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n;
pair<double, double> p[101];

double cost(int x, int y)
{
    double dis = sqrt(pow(p[x].first - p[y].first, 2) + pow(p[x].second - p[y].second, 2));

    return sin(dis);
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].first >> p[i].second;

    int dp[n + 1][n + 1];

    for (int len = 3; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            // dp[l][r]
            if (len == 3)
                dp[l][r] = 0;

            double ans = 1e18;
            for (int x = l + 1; x <= r - 1; x++)
            {
                if (x == l + 1)
                    ans = min(ans, cost(l + 1, r) + dp[l + 1][r]);
                else if (x == r - 1)
                    ans = min(ans, cost(l, r - 1) + dp[l][r - 1]);
                else
                    ans = min(ans, cost(l, x) + cost(r, x) + dp[l][x] + dp[x][r]);
            }

            dp[l][r] = ans;
        }
    }

    cout << fixed << setprecision(2) << dp[1][n] << "\n";
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