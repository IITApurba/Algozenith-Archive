#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n, m;
int happy[105][105];

int dp[51][1 << 10 + 1];

int rec(int level, int mask)
{
    if (level == m)
        return 0;

    if (dp[level][mask] != -1)
        return dp[level][mask];

    // Case 1: Skip assigning this student to any rank
    int ans = rec(level + 1, mask);

    // Case 2: Try assigning the student to an available rank
    for (int j = 0; j < n; j++)

        if ((mask & (1 << j)) == 0) // Check if rank level is available
            ans = max(ans, happy[level][j] + rec(level + 1, mask | (1 << j)));

    return dp[level][mask] = ans;
}

// TC : o(n * m * 2^n)

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> happy[i][j];

    memset(dp, -1, sizeof(dp));

    int ans = rec(0, 0);

    cout << ans << endl;
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