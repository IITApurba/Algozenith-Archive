#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n;
int arr[1010];
int dp[1001][1001];
int done[1001][1001];

int rec(int i, int x)
{
    // # of ways to make sum = x from elements [i...N)

    //  pruning
    if (x < 0)
        return 0;

    // base case
    if (i == n)
        if (x == 0)
            return 1;
        else
            return 0;

    // cache check
    if (done[i][x])
        return dp[i][x];

    // Calculate
    int ans = rec(i + 1, x) + rec(i + 1, x - arr[i]);

    // save and return
    done[i][x] = 1;
    return dp[i][x] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int x;
    cin >> x;
    memset(dp, -1, sizeof(dp));

    cout << rec(0, x) << endl;
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