#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n;
int a[3003];
int dp[3003][3003];

int rec(int l, int r)
{
    if (l > r)
        return 0;

    if (dp[l][r] != -1e18)
        return dp[l][r];

    // Player can choose either left or right
    // Next player's net gain is subtracted
    int ans = max(a[l] - rec(l + 1, r), a[r] - rec(l, r - 1));

    return dp[l][r] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1e18;

    cout << rec(0, n - 1) << endl;
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
