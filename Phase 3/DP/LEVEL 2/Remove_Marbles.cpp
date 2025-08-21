#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int arr[105];
int dp[105][105][105];
// dp[l][r][k] = max score from l to r with k same elements as arr[r]
int rec(int l, int r, int k)
{
    if (l > r)
        return 0;
    if (dp[l][r][k] != -1)
        return dp[l][r][k];

    int res = rec(l, r - 1, 0) + (k + 1) * (k + 1);

    for (int i = l; i < r; i++)
    {
        if (arr[i] == arr[r])
        {
            res = max(res, rec(l, i, k + 1) + rec(i + 1, r - 1, 0));
        }
    }

    return dp[l][r][k] = res;
}

void solve()
{
    int n;
    cin >> n;
    for (auto &x : arr)
        cin >> x;

    memset(dp, -1, sizeof(dp));

    cout << rec(0, n - 1, 0) << '\n';
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
