#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

// Question 2 Given an array where every element occurs an even number of times, except one element which occurs an odd number of times. Find the element that occurs an odd number of times.

#define int long long

void solve()
{

    vector<int> a = {15, 19, 12, 15, 19, 19, 19};
    int n = a.size();

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ a[i];
    }

    cout << ans << endl;
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