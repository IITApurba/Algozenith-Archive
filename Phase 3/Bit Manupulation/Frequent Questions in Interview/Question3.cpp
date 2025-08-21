#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif
// Question 3 Given an array where every element occurs twice, except two elements which occur only once. Find both the elements which occur only once.
#define int long long

void solve()
{
    vector<int> a = {23, 23, 4, 3, 5, 3, 15, 15};
    int n = a.size();

    int x = 0;
    for (int i = 0; i < n; i++)
        x ^= a[i];

    // X = A^B
    // We need to find A and B

    // X -> 0101
    int set_bit = x & ~(x - 1);
    int X1 = 0, X2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (set_bit & a[i])
            X1 ^= a[i];
        else
            X2 ^= a[i];
    }

    debug(X1, X2);
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