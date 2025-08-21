#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n, m;
int arr[1001][1001];

// int dp[101][101][101][101];
int dp[101][101][101];

int dx[] = {0, 1};
int dy[] = {1, 0};

bool check(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int rec(int i, int j, int a)
{ // max collection to reach (n-1,m-1)

    int b = i+j-a;

    // pruning
    if(!check(i, j) || !check(a, b))
        return -1e18;

    // base case
    if (i == n - 1 && j == m - 1)
        return arr[i][j];

    // cache check
    if (dp[i][j][a] != -1)
        return dp[i][j][a];

    // transition
    int initial_cost = arr[i][j] + arr[a][b];

    if (a == i && b == j)
        initial_cost = arr[i][j];

    int ans = -1e18;

    for (int k1 = 0; k1 < 2; k1++)
    {
        for (int k2 = 0; k2 < 2; k2++)
        {
            int ni = i + dx[k1];
            int nj = j + dy[k1];
            int na = a + dx[k2];
            int nb = b + dy[k2];

            // bounds check
            if (check(ni, nj) && check(na, nb))
                ans = max(ans, initial_cost + rec(ni, nj, na));
        }
    }

    return dp[i][j][a] = ans;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> arr[i][j];

    memset(dp, -1, sizeof(dp));

    int ans = rec(0, 0, 0);

    cout << ans << "\n";
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