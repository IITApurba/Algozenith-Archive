#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

string a, b, c;
int n, m, l;

int dp[101][101][101];

int rec(int i, int j, int k)
{
    // base case
    if (i == n || j == m || k == l)
        return 0;

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    // COMPUTE
    int ans = 0;
    if (a[i] == b[j] && b[j] == c[k])
        ans = 1 + rec(i + 1, j + 1, k + 1);
    else
        ans = max({rec(i + 1, j, k), rec(i, j + 1, k), rec(i, j, k + 1)});

    return dp[i][j][k] = ans;
}

void solve()
{
    cin >> a >> b >> c;
    n = a.size();
    m = b.size();
    l = c.size();

    memset(dp, -1, sizeof(dp));

    int ans = rec(0, 0, 0);

    cout << ans << endl;
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