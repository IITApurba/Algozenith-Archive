#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n;
int a[1010];
int p[1010];

int done[1010][1010];
int dp[1010][1010];

int rec(int i, int k)
{
    if (i < 0)
        if (k == 0)
            return 0;
        else
            return -1e18;

    if (done[i][k])
        return dp[i][k];

    int ans = rec(i - 1, k);
    for (int j = 1; j <= i + 1; j++)
    {
        ans = max(ans, rec(i - j, k - 1) + p[i] - p[i - j]);
    }

    done[i][k] = 1;

    return dp[i][k] = ans;
}

void solve()
{
    int k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    p[0] = 0;
    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i - 1];

    cout << rec(n - 1, k) << "\n";
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