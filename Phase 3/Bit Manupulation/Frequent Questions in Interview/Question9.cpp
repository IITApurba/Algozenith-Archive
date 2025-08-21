#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

// Question 9 Given an array of integers, find the minimum xor of a pair of elements of the array

void solve()
{
    vector<int> arr = {2, 5, 4, 2, 6, 8, 9};
    int n = arr.size();

    sort(arr.begin(), arr.end());

    int res = INT_MAX;
    
    for (int i = 1; i < n; i++)
        res = min(res, arr[i] ^ arr[i - 1]);

    debug(res);
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