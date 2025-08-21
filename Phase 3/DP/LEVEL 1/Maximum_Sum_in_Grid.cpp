#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int getBestSubarray(vector<int> &a)
{
    int n = a.size();
    int ans = -1e18;
    int sum = 0;
    int minSum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        ans = max(ans, sum - minSum);
        minSum = min(minSum, sum);
    }

    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    // assuming m < n

    int ans = -1e18;

    if (m < n)
    {
        for (int c1 = 0; c1 < m; c1++)
        {
            vector<int> rowSum(n, 0);
            for (int c2 = c1; c2 < m; c2++)
            {
                for (int i = 0; i < n; i++)
                    rowSum[i] += a[i][c2];

                ans = max(ans, getBestSubarray(rowSum));
            }
        }
    }
    else
    {
        for (int c1 = 0; c1 < n; c1++)
        {
            vector<int> rowSum(m, 0);
            for (int c2 = c1; c2 < n; c2++)
            {
                for (int i = 0; i < m; i++)
                    rowSum[i] += a[c2][i];

                ans = max(ans, getBestSubarray(rowSum));
            }
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