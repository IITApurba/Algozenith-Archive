#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

// Question 4 Find the XOR of numbers from 1 to n

int find_xor_upto_n(int n)
{
    int rem = n % 4;

    if (rem == 0)
        return n;
    else if (rem == 1)
        return 1;
    else if (rem == 2)
        return n + 1;
    else if (rem == 3)
        return 0;
}

void solve()
{
    int n;
    cin >> n;

    int ans = find_xor_upto_n(n);

    debug(ans);

    // L^(L+1)^(L+2)^...^R
    // F(R)^F(L-1)

    // XOR(L to R)=find_xor_upto_n(R)⊕find_xor_upto_n(L−1)

    int l, r;
    cin >> l >> r;

    ans = find_xor_upto_n(r) ^ find_xor_upto_n(l - 1);

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