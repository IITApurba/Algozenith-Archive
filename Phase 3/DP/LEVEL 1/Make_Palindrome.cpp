#include <bits/stdc++.h>
using namespace std;

#define int long long
int n;
string a, b;
int dp[1010][1010];

int rec(int i, int j)
{
    if (i == n || j == n)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;

    if (a[i] == b[j])
        ans = 1 + rec(i + 1, j + 1);
    else
        ans = max(rec(i + 1, j), rec(i, j + 1));

    return dp[i][j] = ans;
}

void solve()
{
    cin >> a;
    n = a.size();

    b = a;
    reverse(b.begin(), b.end());

    memset(dp, -1, sizeof(dp));

    int ans = rec(0, 0);

    cout << n - ans << endl;
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