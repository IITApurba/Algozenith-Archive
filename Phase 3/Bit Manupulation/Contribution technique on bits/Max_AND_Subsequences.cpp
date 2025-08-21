#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 0;

    for (int i = 30 - 1; i >= 0; i--)
    {

        vector<int> elementBitSet;

        for (auto v : arr)
        {
            if (v & (1 << i))
            {
                elementBitSet.push_back(v);
            }
        }
        if (elementBitSet.size() >= x)
        {
            ans += (1LL << i);
            arr = elementBitSet;
        }
    }

    cout << ans << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}