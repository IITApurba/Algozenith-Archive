#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> dp(n, 1), cnt(n, 1);

    int maxi = 1;

    debug(arr);  // log the input array

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
            {
                debug(i, prev, arr[prev], arr[i], dp[prev], dp[i], cnt[prev]);
                dp[i] = 1 + dp[prev];
                cnt[i] = cnt[prev];
                debug("Updated dp[i] and cnt[i]", i, dp[i], cnt[i]);
            }
            else if (arr[prev] < arr[i] && 1 + dp[prev] == dp[i])
            {
                debug(i, prev, arr[prev], arr[i], dp[prev], dp[i], cnt[i], cnt[prev]);
                cnt[i] += cnt[prev];
                debug("Increased cnt[i]", i, cnt[i]);
            }
        }
        maxi = max(maxi, dp[i]);
        debug("maxi after index", i, maxi);
    }

    int nos = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxi)
        {
            nos += cnt[i];
            debug("Adding cnt[i] to nos", i, cnt[i], nos);
        }
    }

    debug(dp, cnt, maxi, nos);  // Final state before output
    cout << nos << "\n";
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
