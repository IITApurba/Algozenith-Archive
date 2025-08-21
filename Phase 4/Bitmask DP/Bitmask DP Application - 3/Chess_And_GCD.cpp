#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n;
int a[22];
int dp[(1 << 20) + 7];
vector<int> pre_bits[(1 << 20)];
int pre_gcd[20][20];

int bestPairing(int board, int mask)
{
    if (board == n + 1)
        return 0;

    if (dp[mask] != -1)
        return dp[mask];

    int ans = 0;
    // Iterate only over free bits precomputed
    for (int i = 0; i < (int)pre_bits[mask].size(); i++)
    {
        for (int j = i + 1; j < (int)pre_bits[mask].size(); j++)
        {
            int u = pre_bits[mask][i];
            int v = pre_bits[mask][j];
            ans = max(ans, bestPairing(board + 1, mask | (1 << u) | (1 << v)) + board * abs(a[u] - a[v]) * pre_gcd[u][v]);
        }
    }
    return dp[mask] = ans;
}

void solve()
{
    cin >> n;
    n *= 2;

    // Precompute free bits for all masks
    for (int mask = 0; mask < (1 << n); mask++)
    {
        pre_bits[mask].clear();
        for (int bit = 0; bit < n; bit++)
            if ((mask & (1 << bit)) == 0)
                pre_bits[mask].push_back(bit);
    }

    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Precompute gcd for all pairs
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            pre_gcd[i][j] = __gcd(a[i], a[j]);

    memset(dp, -1, sizeof(dp));

    int ans = bestPairing(1, 0);

    cout << ans << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
