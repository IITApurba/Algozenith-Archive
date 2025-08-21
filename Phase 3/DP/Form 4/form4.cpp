#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n;
int a[101];
int dp[101][101];
int prefix[101];

int getsum(int l, int r)
{
    return prefix[r] - ((l == 0) ? 0 : prefix[l - 1]);
}

int rec(int l, int r)
{
    // base case
    if (l == r)
        return 0;

    // cache check
    if (dp[l][r] != -1)
        return dp[l][r];

    int ans = 1e18;
    for (int mid = l; mid < r; mid++)
    {
        ans = min(ans,
                  rec(l, mid) + rec(mid + 1, r) +
                      (getsum(l, mid) % 100) * (getsum(mid + 1, r) % 100));
    }

    return dp[l][r] = ans;
}

void gen(int l, int r)
{
    if (l == r)
        return;

    for (int mid = l; mid < r; mid++)
    {
        if (rec(l, r) == rec(l, mid) + rec(mid + 1, r) +
                             (getsum(l, mid) % 100) * (getsum(mid + 1, r) % 100))
        {
            gen(l, mid);
            gen(mid + 1, r);
            cout << "Merge (" << l << " , " << mid << ") and (" << mid + 1 << " , " << r << ")" << endl;
            return;
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
            prefix[i] = a[i];
        else
            prefix[i] = prefix[i - 1] + a[i];
    }
    debug(a);
    debug(prefix);

    memset(dp, -1, sizeof(dp));

    cout << rec(0, n - 1) << endl;
    gen(0,n-1);
    cout << endl;
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