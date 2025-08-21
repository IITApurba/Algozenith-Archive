#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n;
int a[100100], b[100100], c[100100];

int dp[100100][4];

/*
a - > 1
b -> 2
c -> 3
*/

int rec(int i, int prev)
{
    // base case
    if (i == n)
        return 0;

    // cache check
    if (dp[i][prev] != -1)
        return dp[i][prev];

    // computation
    int ans = 0;

    if (prev == 1)
        ans = max(b[i] + rec(i + 1, 2), c[i] + rec(i + 1, 3));
    else if (prev == 2)
        ans = max(a[i] + rec(i + 1, 1), c[i] + rec(i + 1, 3));
    else if (prev == 3)
        ans = max(a[i] + rec(i + 1, 1), b[i] + rec(i + 1, 2));

    // save and return
    return dp[i][prev] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];

    memset(dp, -1, sizeof(dp));

    int ans = max({rec(0, 1), rec(0, 2), rec(0, 3)});

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