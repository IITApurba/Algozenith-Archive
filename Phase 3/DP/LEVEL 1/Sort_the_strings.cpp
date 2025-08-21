#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n;
vector<int> c;
vector<string> s, rev;
vector<vector<int>> dp;

int recurse(int i, int revFlag)
{
    if (i == 0)
        return revFlag ? c[0] : 0;
    if (dp[i][revFlag] != -1)
        return dp[i][revFlag];

    int ans = 1e18;
    string curr = revFlag ? rev[i] : s[i];

    // Try previous not reversed
    string prev = s[i - 1];
    if (prev <= curr)
        ans = min(ans, recurse(i - 1, 0) + (revFlag ? c[i] : 0));

    // Try previous reversed
    prev = rev[i - 1];
    if (prev <= curr)
        ans = min(ans, recurse(i - 1, 1) + (revFlag ? c[i] : 0));

    return dp[i][revFlag] = ans;
}

void solve()
{
    cin >> n;
    c.resize(n);
    s.resize(n);
    rev.resize(n);
    dp.assign(n, vector<int>(2, -1));

    for (int i = 0; i < n; ++i)
        cin >> c[i];
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
        rev[i] = s[i];
        reverse(rev[i].begin(), rev[i].end());
    }

    int ans = min(recurse(n - 1, 0), recurse(n - 1, 1));
    if (ans == 1e18)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
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
