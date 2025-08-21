#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
const int INF = 1e9;
int n;
int w[3003], v[3003];
int W, k, m;
int dp[101][101][101];

// O(N*W*k)
int rec(int level, int w_left, int item_left)
{
    // max value you can make in [i...n], where X is the weight left and
    // item_left is the number of item left to be taken at max.
    //  pruning
    //  basecase
    if (level == n)
    {
        int sum_of_take = (W - w_left);
        if (sum_of_take % m == 0)
        {
            // vaid
            return 0;
        }
        else
        {
            //invalid
            return -INF;
        }
    }

    // cache check
    if (dp[level][w_left][item_left] != -1)
        return dp[level][w_left][item_left];

    // transition
    int ans = rec(level + 1, w_left, item_left);
    if (w[level] <= w_left && item_left > 0)
        ans = max(ans, rec(level+2, w_left - w[level], item_left - 1) + v[level]);

    // save and return
    return dp[level][w_left][item_left] = ans;
}

void solve()
{
    cin >> n >> W >> k >> m;

    for (int i = 0; i < n; i++)
        cin >> w[i];

    for (int i = 0; i < n; i++)
        cin >> v[i];

    memset(dp, -1, sizeof(dp));

    cout << rec(0, W, k) << endl;

    cout << endl;
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