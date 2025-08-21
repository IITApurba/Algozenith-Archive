#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n, k;
int a[1000005];
int dp[1000005];

int rec(int x)
{
    // base case
    if (x == 0)
        return 0;

    // pruning
    if (x < 0)
        return 0;

    // cache check
    if (dp[x] != -1)
        return dp[x];

    // compute
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (x >= a[i] && rec(x - a[i]) == 0)
        {
            ans = 1;
            break;
        }
    }

    // save and return
    return dp[x] = ans;
}

void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    memset(dp, -1, sizeof(dp));

    if (rec(k))
        cout << "First" << endl;
    else
        cout << "Second" << endl;
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