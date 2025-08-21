#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

void solve()
{
    int n;
    cin >> n;
    bitset<3> a;

    for (int mask = 0; mask < (1 << n); mask++)
    {
        a = mask;
        cout << a.to_string() << endl;

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";

        cout << endl;
    }

    bitset<4> x("1010");
    bitset<4> y("0101");
    debug(x, y);
    cout << "X: " << x << endl;
    cout << "Y: " << y << endl;

    cout << (x & y) << endl;

    int z = 0b1001;
    cout << z << endl;
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