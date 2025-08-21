#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

void solve()
{
    int n, target;
    cin >> n >> target;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int ans;

    for (int i = 1; i < n - 1; i++)
    {
        int lo = 0, hi = n - 1;

        while (1)
        {
            if()
        }
        
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