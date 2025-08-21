#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

// Question 7 Given an array of integers, find the xor of elements of all the subarrays possible

int find_xor_of_subarrays(vector<int> &arr)
{
    int n = arr.size();
    int ans = 0;
    if (n % 2 == 0)
        return 0;
    for (int i = 0; i < n; i += 2)
    {
        ans ^= arr[i];
    }
    return ans;
}

void solve()
{
    vector<int> arr = {12, 15, 6, 7, 9, 14, 18};
    int n = arr.size();

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int freq = (i + 1) * (n - i);

        if (freq % 2 == 1)
            ans = ans ^ arr[i];
    }

    debug(ans);

    ans = find_xor_of_subarrays(arr);

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