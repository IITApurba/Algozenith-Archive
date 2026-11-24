/*
  Problem : Bit Magic II
  Link    : https://maang.in/problems/Bit-Magic-II-873
  Given   : Integer n (t test cases).
  Find    : 6 answers: 64-bit binary of n, MSB position, rightmost set bit position, is power of 2?, largest power of 2 dividing n, smallest power of 2 >= n.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;

    // Part 1: print the 64-bit binary representation of n
    bitset<64> bits(n);

    cout << bits << endl;

    // Part 2: position of the MSB (leftmost set bit), 0-indexed
    //         n == 0 -> print -1
    if (n == 0)
        cout << -1 << endl;
    else
        for (int i = 63; i >= 0; i--)
            if (bits[i] == 1)
            {
                cout << i << endl;
                break;
            }

    // Part 3: position of the rightmost set bit, 0-indexed
    //         n == 0 -> print -1
    if (n == 0)
        cout << -1 << endl;
    else
        for (int i = 0; i < 64; i++)
            if (bits[i] == 1)
            {
                cout << i << endl;
                break;
            }

    // Part 4: print 1 if n is a power of 2 (n == 2^x, x > 0), else 0
    if ((n & (n - 1)) == 0 && n > 1)
        cout << 1 << endl;
    else
        cout << 0 << endl;

    // Part 5: biggest power of 2 that divides n (the value 2^k, not k)
    //         n == 0 -> print -1
    if (n == 0)
        cout << -1 << endl;
    else
        cout << (n & -n) << endl;

    // Part 6: smallest power of 2 that is >= n (the value 2^k, k > 0)
    //         k > 0 means the answer is at least 2
    long long ans = 2;
    while (ans < n)
        ans = ans * 2;
    cout << ans << endl;
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