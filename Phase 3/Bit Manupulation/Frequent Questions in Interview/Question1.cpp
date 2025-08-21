#include <bits/stdc++.h>
using namespace std;
#define int long long

// Question 1 Given an array where every element occurs three times, except one element which occurs only once. Find the element that occurs once.

void solve()
{
    vector<int> arr = {1, 2, 3, 2, 3, 3, 2};

    int n = arr.size();
    int ans = 0;

    for (int i = 0; i < 30; i++) // Iterate over each bit position
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] & (1LL << i)) // Check if i-th bit is set
                cnt++;
        }

        if (cnt % 3 == 1) // If bit appears non-multiple of 3 times, set it in ans
        {
            ans = ans | (1LL << i);
        }
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
