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

    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int mask = 0; mask < (1 << n); mask++)
    {
        cout << mask << " : ";

        // mask = 2 -> 010

        for (int i = 0; i < n; i++)
        {
            if (((mask >> i) & 1) == 0)
                cout << a[i] << ", ";
        }

        cout << endl;
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