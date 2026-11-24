#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;

    bitset<32> bit(n);

    string s = bit.to_string();

    reverse(s.begin(),s.end());

    bitset<32> rev_bit(s);

    cout << rev_bit.to_ullong() << endl;
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