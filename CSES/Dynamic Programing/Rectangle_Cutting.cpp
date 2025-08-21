#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

const int INF = 1e9;
int dp[501][501];

int minCuts(int a, int b)
{
    if (a == b)
        return 0; // already a square

    if (dp[a][b] != -1)
        return dp[a][b];

    int res = INF;

    // Horizontal cuts
    for (int i = 1; i < a; ++i)
    {
        res = min(res, 1 + minCuts(i, b) + minCuts(a - i, b));
    }

    // Vertical cuts
    for (int j = 1; j < b; ++j)
    {
        res = min(res, 1 + minCuts(a, j) + minCuts(a, b - j));
    }

    return dp[a][b] = res;
}

void solve()
{
    int a, b;
    cin >> a >> b;

    memset(dp, -1, sizeof(dp));

    cout << minCuts(a, b) << '\n';
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
