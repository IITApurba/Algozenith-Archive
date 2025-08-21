#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n;
vector<int> weight, value;
int dp[1001][10001]; // Assuming max n = 1000, max W = 10000

int rec(int i, int w)
{
    if (i == n && w == 0)
        return 0;

    if (dp[i][w] != -1)
        return dp[i][w];

    int ans = rec(i + 1, w); // don't take

    if (w >= weight[i]) // take
        ans = max(ans, value[i] + rec(i + 1, w - weight[i]));

    return dp[i][w] = ans;
}

void solve()
{
    cin >> n;
    weight.resize(n);
    value.resize(n);

    for (int i = 0; i < n; i++)
        cin >> weight[i];
    for (int i = 0; i < n; i++)
        cin >> value[i];

    int W;
    cin >> W;

    memset(dp, -1, sizeof(dp)); // initialize memo table

    int ans = rec(0, W);
    cout << ans << endl;
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
