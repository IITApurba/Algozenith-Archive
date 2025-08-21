#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
using ll = long long;

ll sum_of_bits(ll x)
{
    ll ans = 0;
    ll tot = x + 1;
    for (int i = 0; i < 60; i++)
    {
        ll full = tot / (1LL << (i + 1));
        ll left = tot % (1LL << (i + 1));
        ll extra = max((left - (1LL << i)), 0LL);

        ans += full * (1LL << i) + extra;
    }

    return ans;
}

void solve()
{

    int q;
    cin >> q;

    while (q--)
    {
        int k;
        cin >> k;

        
    }
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