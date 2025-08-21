#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

// Question 6 Given a positive integer n, find the count of positive integers i such that 0 <= i <= n and n+i=n^i

// n+i = n^i
// Xor means addition without carry
// n&i = 0

void solve()
{
    int n;
    cin >> n;

    int count_unset = 0;

    while (n > 0)
    {
        if ((n & 1) == 0)
            count_unset++;
        n >>= 1;
    }

    // There can be 2^count numbers
    int ans = 1 << count_unset;

    debug(ans);
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