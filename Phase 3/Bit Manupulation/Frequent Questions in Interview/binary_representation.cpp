#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

void printBin(unsigned int x)
{
    if (x > 1)
        printBin(x / 2);

    cout << x % 2;
}

void solve()
{
    unsigned int x;
    cin >> x;

    // From MSB -> LSB
    for (int i = 3; i >= 0; i--)
    {
        // Testing wether ith bit is 1 or 0
        // 1LL is very important!!!
        // Use it everytime
        if (x & (1LL << i))
            cout << 1;
        else
            cout << 0;
    }

    cout << endl;

    printBin(x);

    cout << endl;
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