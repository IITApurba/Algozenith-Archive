#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
#define double long double

pair<double, double> p[105];
double dp[105][105];
int n;

double sq(double x)
{
    return x * x;
}

double dist(int i, int j)
{
    return sqrt(sq(p[i].first - p[j].first) + sq(p[i].second - p[j].second));
}

double triangleCost(int i, int j, int k)
{
    return sin(dist(i, j)) + sin(dist(j, k)) + sin(dist(k, i));
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].first >> p[i].second;

    for (int len = 3; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            dp[i][j] = 0;
            for (int k = i + 1; k < j; k++)
            {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + triangleCost(i, k, j));
            }
        }
    }

    cout << fixed << setprecision(10) << dp[1][n] << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
