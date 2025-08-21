#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

const int N = 20; // Maximum number of nodes
int n; // Number of nodes
int dp[1 << N]; // DP array for memoization
bool adj[N][N]; // Adjacency matrix to store edges



int rec(int mask)
{
    if (mask == (1 << n) - 1)
        return 0; // All nodes chosen in topological order
    if (dp[mask] != -1)
        return dp[mask];

    int ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        if ((mask >> i) & 1)
            continue; // Node i already in mask

        int newMask = mask | (1 << i);
        int removeEdges = 0;
        for (int j = 0; j < n; j++)
        {
            if (((mask >> j) & 1) && adj[i][j])
            {
                removeEdges++; // Count edges i → j that must be removed
            }
        }
        ans = min(ans, removeEdges + rec(newMask));
    }

    return dp[mask] = ans;
}

void solve()
{
    cin >> n;
    
    

    memset(dp, -1, sizeof(dp));

    cout << rec(0) << endl;
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