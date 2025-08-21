#include <bits/stdc++.h>
using namespace std;

#define int long long

int prefSum[1000001][31];

void solve()
{
    int n, q;
    int i;
    cin >> n;
    for (i = 0; i <= n; i++)
        for (int j = 0; j < 31; j++)
            prefSum[i][j] = 0;
    for (i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        int cnt = 0;
        while (a > 0)
        {
            prefSum[i][cnt] = a % 2;
            a /= 2;
            cnt++;
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (int j = 0; j < 31; j++)
            prefSum[i][j] += prefSum[i - 1][j];
    }
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        double total = (r - l + 1.0) / (2);
        long long x1 = 0, x2 = 0, x3 = 0;
        for (i = 0; i < 31; i++)
        {
            int p = prefSum[r][i] - prefSum[l - 1][i];
            if (p < total)
                x1 += (1LL << i);
            if (p != (r - l + 1))
                x2 += (1LL << i);
            if (p)
                x3 += (1LL << i);
        }
        long long ans = x1 + x2 + x3;
        cout << ans << "\n";
    }
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