#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n;
int a[101];
set<int> sums;
int dp[101][100100];

void rec(int x, int sum)
{
    if (dp[x][sum])
        return;

    dp[x][sum] = 1;

    if (x == n)
    {
        if (sum > 0)
            sums.insert(sum);
        return;
    }

    rec(x + 1, sum + a[x]);

    rec(x + 1, sum);
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    memset(dp, 0, sizeof(dp));

    rec(0, 0);

    cout << sums.size() << '\n';
    for (int x : sums)
        cout << x << " ";
    cout << '\n';
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
