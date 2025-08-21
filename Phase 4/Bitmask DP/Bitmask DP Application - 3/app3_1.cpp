#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n;
int a[40];

int dp[(1 << 20)];

int bestPairing(int board, int mask)
{
    if (board == n + 1)
        return 0;

    if (dp[mask] != -1)
        return dp[mask];

    int ans = 0;

    int i = log2(mask ^ (mask | mask + 1));

    for (int j = 0; j < 2 * n; j++)

        if ((mask & ((1 << i) | (1 << j))) == 0)

            ans = max(ans, bestPairing(board + 1, mask | (1 << i) | (1 << j)) + abs(a[i] - a[j]) * __gcd(a[i], a[j]));

    return dp[mask] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < 2 * n; i++)
        cin >> a[i];

    memset(dp, -1, sizeof(dp));

    int ans = bestPairing(1, 0LL);

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