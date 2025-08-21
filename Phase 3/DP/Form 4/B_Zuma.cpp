#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n;
int a[505];
int dp[505][505];

int rec(int l, int r)
{
    // Base case
    if (l >= r)
        return 1;

    // Cache Check
    if (dp[l][r] != -1)
        return dp[l][r];

    // Compute answer
    int ans = n;
    if (a[l] == a[r])
        ans = rec(l + 1, r - 1);

    for (int mid = l; mid < r; mid++)
    {
        int leftAns = rec(l, mid);
        int rightAns = rec(mid + 1, r);
        ans = min(ans, leftAns + rightAns);
    }

    // Save and return
    return dp[l][r] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    memset(dp, -1, sizeof(dp));

    int ans = rec(0, n - 1);

    cout << ans << endl;
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