#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int dp[1000005]; // Assumes n <= 1e6

int rec(int n)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int ans = 1e9;
    int temp = n;

    while (temp > 0)
    {
        int d = temp % 10;
        temp /= 10;

        if (d > 0)
            ans = min(ans, 1 + rec(n - d));
    }

    return dp[n] = ans;
}

void solve()
{
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));
    cout << rec(n) << "\n";
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
