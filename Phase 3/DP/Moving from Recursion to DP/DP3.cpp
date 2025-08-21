#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, x, k;
int t[1001], s[1001];
int dp[1001][1001][101]; // Assuming max time is 1000 and max items is 100

int rec(int level, int timespend, int itemtaken)
{
    cout << "Entering rec(level=" << level << ", timespend=" << timespend << ", itemtaken=" << itemtaken << ")" << endl;

    // Base case: If all items are considered
    if (level == n)
    {
        cout << "Base case reached at level " << level << endl;
        return 0;
    }

    // Memoization check
    if (dp[level][timespend][itemtaken] != -1)
    {
        cout << "Using memoized value for level=" << level << ", timespend=" << timespend << ", itemtaken=" << itemtaken << " -> " << dp[level][timespend][itemtaken] << endl;
        return dp[level][timespend][itemtaken];
    }

    // Choice 1: Don't take this item
    int ans = rec(level + 1, timespend, itemtaken);
    cout << "After skipping item " << level << ", ans=" << ans << endl;

    // Choice 2: Take this item if constraints allow
    if (timespend + t[level] <= x && itemtaken + 1 <= k)
    {
        cout << "Taking item " << level << " with skill " << s[level] << endl;
        ans = max(ans, s[level] + rec(level + 1, timespend + t[level], itemtaken + 1));
    }

    cout << "Computed dp[level=" << level << ", timespend=" << timespend << ", itemtaken=" << itemtaken << "] = " << ans << endl;
    return dp[level][timespend][itemtaken] = ans;
}

void solve()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> t[i] >> s[i];

    cin >> x >> k;

    // Initialize DP table with -1
    memset(dp, -1, sizeof(dp));

    cout << "Starting new test case with n=" << n << ", x=" << x << ", k=" << k << endl;
    cout << "Maximum skill points: " << rec(0, 0, 0) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while (t--)
    {
        cout << "=================================" << endl;
        solve();
    }

    return 0;
}
