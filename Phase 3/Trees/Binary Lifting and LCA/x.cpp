#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
const int LOG = 20; // supports up to 2^20 ≈ 10^6 steps
const int MAXN = 200005;

int up[MAXN][LOG]; // up[i][j] = the 2^j-th successor of i

void solve()
{
    int n;
    cin >> n;
    vector<int> next(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> next[i];
    }

    // 1) Build binary‑lifting table
    for (int i = 1; i <= n; i++)
    {
        up[i][0] = next[i]; // 2^0 = 1‑step jump
    }
    for (int j = 1; j < LOG; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            int mid = up[i][j - 1];
            up[i][j] = (mid ? up[mid][j - 1] : 0);
        }
    }

    // 2) Answer queries
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        int x, k;
        cin >> c >> x >> k;
        if (c == '?')
        {
            for (int j = 0; j < LOG && x; j++)
            {
                if (k & (1LL << j))
                {
                    x = up[x][j];
                }
            }
            cout << x << "\n";
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // If there were multiple test cases, you could uncomment:
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
