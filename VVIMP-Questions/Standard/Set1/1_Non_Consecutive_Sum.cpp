#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 1;

int dp[N];
int n;
vector<int> arr;

int rec(int lvl)
{
    // base case
    if (lvl == n)
        return 0;
    // pruning
    if (lvl > n)
        return 0;

    // cache check
    if (dp[lvl] != -1)
        return dp[lvl];

    // tranistion
    int take = arr[lvl] + rec(lvl + 2);
    int not_take = rec(lvl + 1);

    int ans = max(take, not_take);

    // save and return
    return dp[lvl] = ans;
}

void solve()
{
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    memset(dp, -1, sizeof(dp));

    int ans = rec(0);

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}