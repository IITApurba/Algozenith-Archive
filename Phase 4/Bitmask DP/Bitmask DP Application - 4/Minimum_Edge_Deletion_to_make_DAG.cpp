#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 16; // Maximum number of nodes
int n;            // Number of nodes
int dp[1 << N];   // DP array for memoization
bool adj[N][N];   // Adjacency matrix to store edges

int rec(int mask)
{
    if (mask == (1 << n) - 1)
        return 0;
    if (dp[mask] != -1)
        return dp[mask];

    int ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        if ((mask >> i) & 1)
            continue;

        int newMask = mask | (1 << i);
        int cost = 0;
        for (int j = 0; j < n; j++)
        {
            if (((mask >> j) & 1) && adj[i][j])
            {
                cost++;
            }
        }
        ans = min(ans, cost + rec(newMask));
    }

    return dp[mask] = ans;
}

void solve()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << rec(0) << endl;
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