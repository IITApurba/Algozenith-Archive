#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n, m;
string s, t;
int dp[1001][1001];

int rec(int i, int j)
{
    // base case
    if (i == n || j == m)
        return 0;

    // cache check
    if (dp[i][j] != -1)
        return dp[i][j];
    // compute
    int ans = 0;

    if (s[i] == t[j])
        ans = 1 + rec(i + 1, j + 1);

    return dp[i][j] = ans;
}

void solve()
{
    cin >> n >> m;
    cin >> s >> t;

    memset(dp, -1, sizeof(dp));

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans = max(ans, rec(i, j));
        }
    }
    cout << ans << endl;
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