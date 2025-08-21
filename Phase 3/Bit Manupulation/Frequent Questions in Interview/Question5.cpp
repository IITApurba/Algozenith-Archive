#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

// Question 5 One number is missing from the list of integers from 1 to n. Find that missing number

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;

    for (int i = 1; i <= n + 1; i++)
        ans = ans ^ i;

    for (int i = 0; i < n; i++)
        ans = ans ^ a[i];

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