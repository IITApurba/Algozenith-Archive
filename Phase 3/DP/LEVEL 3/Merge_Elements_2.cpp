#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, x, y, z;
int a[51];

int dp[51][51][51];
int visited[51][51];

int recur(int l, int r, int x1)
{
    if (l == r)
    {
        if (a[l] == x1)
            return 0;
        return 1e9;
    }

    if (visited[l][r] != -1)
    {
        return dp[l][r][x1];
    }

    for (int i = 0; i < 50; i++)
    {                     
        dp[l][r][i] = 1e9;
    }

    for (int left = 0; left <= 49; left++)
    {
        for (int right = 0; right <= 49; right++)
        {
            for (int mid = l; mid < r; mid++)
            {
                dp[l][r][(x * left + y * right + z) % 50] = min(dp[l][r][(x * left + y * right + z) % 50], recur(l, mid, left) + recur(mid + 1, r, right) + left * right);
            }
        }
    }

    visited[l][r] = 1;
    return dp[l][r][x1];
}

void solve()
{
    cin >> n >> x >> y >> z;

    memset(dp, 1e9, sizeof(dp));
    memset(visited, -1, sizeof(visited));

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = 1e9;
    for (int i = 0; i < 50; i++)
    {
        ans = min(ans, recur(0, n - 1, i));
    }

    cout << ans << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}