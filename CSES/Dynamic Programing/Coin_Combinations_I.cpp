#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n, c;
vector<int> a;
vector<int> dp;
int mod = 1e9 + 7;

int rec(int x)
{
    if (x == 0)
        return 1;
    if (x < 0)
        return 0;

    if (dp[x] != -1)
        return dp[x] % mod;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = (ans + rec(x - a[i])) % mod;
    }

    return dp[x] = ans;
}

void solve()
{
    cin >> n >> c;
    a.resize(n);
    dp.assign(c + 3, -1);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = rec(c);

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