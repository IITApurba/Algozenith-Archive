#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int dp[k + 1];

    // 0->loosing
    // 1->wining

    dp[0] = 0;

    for (int i = 1; i <= k; i++)
    {
        dp[i] = 0;

        for (int x = 0; x < n; x++)
        {
            if (i>=arr[x] && dp[i - arr[x]] == 0)
            {
                dp[i] = 1;
                break;
            }
        }
    }

    if (dp[k])
        cout << "First" << endl;
    else
        cout << "Second" << endl;
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