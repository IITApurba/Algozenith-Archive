#include <bits/stdc++.h>
using namespace std;

#define int long long

int mod = 1e9 + 7;

int bin_pow(int base, int exp)
{
    base %= mod;
    if (base < 0)
        base += mod; // handle negative base

    int res = 1;
    while (exp > 0)
    {
        if (exp & 1) // current bit is 1, so multiply it in
            res = res * base % mod;
        base = base * base % mod; // square for the next bit
        exp >>= 1;                // move to the next bit
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;

    if (n == 2)
    {
        cout << 1 << "\n";
        return;
    } // 1 + 1
    if (n == 3)
    {
        cout << 2 << "\n";
        return;
    } // 1 + 2

    int ans;
    if (n % 3 == 0)
        ans = bin_pow(3, n / 3); // all 3s
    else if (n % 3 == 1)
        ans = bin_pow(3, n / 3 - 1) * 4 % mod; // 3s + one 4
    else
        ans = bin_pow(3, n / 3) * 2 % mod; // 3s + one 2

    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}