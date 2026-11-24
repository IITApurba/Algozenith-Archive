/*
  Problem : SWAPBIT
  Link    : https://maang.in/problems/SWAPBIT-600
  Given   : Unsigned integer N.
  Find    : N after swapping every odd bit with its neighbouring even bit, in O(1).
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;

    bitset<32> bits(n);

    for (int i = 0; i < 32; i += 2)
    {
        bool temp = bits[i];
        bits[i] = bits[i + 1];
        bits[i + 1] = temp;
        //swap(bits[i],bits[i+1])
    }

    cout << bits.to_ullong() << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}