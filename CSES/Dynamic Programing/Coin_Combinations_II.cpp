#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

const int mod = 1e9 + 7;

int a[105];
int n, c;

void solve()
{
    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> dp(c + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = a[i]; j <= c; j++)
        {
            dp[j] = (dp[j] + dp[j - a[i]]) % mod;
        }
    }

    cout << dp[c] << '\n';
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
