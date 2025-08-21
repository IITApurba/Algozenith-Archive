#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n, target;
int x[105];
int dp[105][10100]; // dp[level][taken]

int rec(int level, int left)
{
    // pruning
    if (left < 0)
        return 0;
    // base case
    if (level == n + 1)
        return (left == 0) ? 1 : 0;

    // cache check
    if (dp[level][left] != -1)
        return dp[level][left];

    // compute
    int ans = 0;

    if (rec(level + 1, left) == 1)
        ans = 1;
    else if (rec(level + 1, left - x[level]))
        ans = 1;

    return dp[level][left] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i];

    memset(dp, -1, sizeof(dp));

    int q;
    cin >> q;
    while (q--)
    {
        cin >> target; // target
        cout << rec(1, target) << endl;
    }
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