#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define endl "\n"
int n, k;
int dp[5001][5001]; // using this dp for all testcases

int rec(int dots, int boxes)
{
    // pruning
    if (dots < 0)
        return 0;

    // base case
    if (dots == 0)
        return 1;
    if (boxes == 0)
        return 0;

    // cache check
    if (dp[dots][boxes] != -1)
        return dp[dots][boxes];

    // compute
    int take = rec(dots - boxes, boxes);
    int not_take = rec(dots, boxes - 1);
    int ans = (take + not_take) % mod;

    // save and return
    return dp[dots][boxes] = ans;
}

void solve()
{
    cin >> n >> k;
    if (n < k)
    {
        cout << 0 << endl;
        return;
    }
    cout << rec(n - k, k) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof(dp));
    int t;
    cin >> t;
    while (t--)
        solve();
}