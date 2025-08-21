#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int mod = 1e9 + 7;
vector<vector<int>> grid;
vector<vector<vector<int>>> dp;
int n, m, k;

int rec(int i, int j, int left)
{

    if (left < 0)
    {
        return 0;
    }

    if (i == n - 1 && j == m - 1)
    {
        if (grid[i][j] == 0 || left > 0)
            return 1;
        return 0;
    }

    if (i == n || j == m)
    {
        return 0;
    }

    if (dp[i][j][left] != -1)
    {
        return dp[i][j][left];
    }

    int ans = 0;
    if (grid[i][j] == 0)
    {
        ans = (rec(i + 1, j, left) % mod + rec(i, j + 1, left) % mod) % mod;
    }
    else
    {
        ans = (rec(i + 1, j, left - 1) % mod + rec(i, j + 1, left - 1) % mod) % mod;
    }

    return dp[i][j][left] = ans % mod;
}

void solve()
{
    cin >> n >> m >> k;
    grid.resize(n, vector<int>(m));
    dp.resize(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int ans = rec(0, 0, k);
    cout << ans << endl;

    dp.clear();
    grid.clear();
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