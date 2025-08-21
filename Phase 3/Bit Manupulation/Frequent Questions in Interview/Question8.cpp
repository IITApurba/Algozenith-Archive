#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int mod = 1e9 + 7;

// Question 8 Suppose f(X, Y) = number of positions in binary representation where bits differ. Given an array of integers, find the sum of f(ai, aj) for every possible i and j in range 1 to n. Find answer modulo 10^9 + 7

void solve()
{
    vector<int> arr = {2, 3, 7, 6, 4};

    int n = arr.size();
    int ans = 0;

    for (int i = 0; i < 31; i++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int j = 0; j < n; j++)
            cnt1 += ((arr[j]) & (i << i) > 0);

        cnt2 = n - cnt1;

        cnt1 %= mod;
        cnt2 %= mod;
        ans = (ans % mod + cnt1 * cnt2) % mod;
    }

    debug(ans);
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