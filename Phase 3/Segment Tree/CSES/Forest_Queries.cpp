#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

void solve()
{
    int n, q;
    cin >> n >> q;
    char arr[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    
    int prefix[n][n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            prefix[i][j] = (arr[i][j] == '*') ? 1 : 0;
            if (i > 0)
                prefix[i][j] += prefix[i - 1][j];
            if (j > 0)
                prefix[i][j] += prefix[i][j - 1];
            if (i > 0 && j > 0)
                prefix[i][j] -= prefix[i - 1][j - 1];
        }
    }

    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;

        int total = prefix[x2][y2];
        if (x1 > 0)
            total -= prefix[x1 - 1][y2];
        if (y1 > 0)
            total -= prefix[x2][y1 - 1];
        if (x1 > 0 && y1 > 0)
            total += prefix[x1 - 1][y1 - 1];

        cout << total << endl;
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