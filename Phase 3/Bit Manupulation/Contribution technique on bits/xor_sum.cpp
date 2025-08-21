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
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;

    for (int j = 0; j < 31; j++)
    {
        int cnt_0 = 0, cnt_1 = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] & (1 << j))
            {
                cnt_1++;
            }
            else
            {
                cnt_0++;
            }
        }

        int pairs = cnt_0 * cnt_1;

        ans += pairs * (1 << j);
    }
    cout << ans;
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