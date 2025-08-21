#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n;
int k;
int h[100100];
int dp[100100];

int rec(int i)
{
    // base case
    if (i == n - 1)
        return 0;

    // cache check
    if (dp[i] != -1)
        return dp[i];

    // computation
    int ans = 1e9;
    for (int j = 1; j <= k; j++)
    {
        if (i + j < n)
            ans = min(ans, (abs(h[i] - h[i+j]) + rec(i + j)));
    }

    // save and return
    return dp[i] = ans;
}

void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    memset(dp, -1, sizeof(dp));

    int ans = rec(0);

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