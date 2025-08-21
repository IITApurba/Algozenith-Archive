#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n, c;
vector<int> a;
int dp[1000007];

int rec(int x)
{
    if (x == 0)
        return 0;
    if (x < 0)
        return 1e18;

    if (dp[x] != -1)
        return dp[x];

    int ans = 1e18;

    for (int i = 0; i < n; i++)
    {
        ans = min(ans, 1 + rec(x - a[i]));
    }

    return dp[x] = ans;
}

void solve()
{
    cin >> n >> c;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    memset(dp, -1, sizeof(dp));

    int ans = rec(c);

    if (ans >= 1e18)
        cout << -1 << endl;
    else
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
