#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int mod = 1e9 + 7;

// Question 10 Find the total number of set bits of all the numbers from 0 to n

void solve()
{
    int n;
    cin >> n;

    int ans = 0;
    int sz = 2;

    for (int i = 0; i < 31; i++)
    {
        if ((1 << i) > n)
            break;

        int k = n / sz;
        int temp = (k * (sz / 2)) % mod;

        ans = (ans + temp) % mod;

        // remaining
        k = n % sz;

        int p = sz / 2;

        if (k >= p)
        {
            k = k - p + 1;
            ans = (ans + k) % mod;
        }

        sz = sz * 2;
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