#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n;
int dp[100100];

int rec(int level) // number of ways to reach n from level
{
    // pruning
    if (level > n)
        return 0;

    // BASE CASE
    if (level == n)
        return 1; // generally in counting problem, it's always 1

    // Memoization check
    if (dp[level] != -1)
        return dp[level];

    int ans = 0;

    // choice... 1,2,3 ways
    for (int step = 1; step <= 3; step++) // Changed step from 0 to 1
    {
        if (level + step <= n)
        {
            ans += rec(level + step); // Accumulate the count of ways
        }
    }

    dp[level] = ans; // Store the result in dp array

    return ans;
}

void solve()
{
    cin >> n;

    memset(dp, -1, sizeof(dp));

    int ans = rec(1);

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
