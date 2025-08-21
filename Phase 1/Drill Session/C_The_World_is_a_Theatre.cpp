#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

ll bin_pow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }

    return res;
}

ll nCr(int n, int r)
{
    if (r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;

    ll res = 1;
    for (int i = 1; i <= r; i++)
    {
        res = res * (n - i + 1);
        res = res / i;
    }

    return res;
}

void solve()
{
    int n, m, t;
    cin >> n >> m >> t;

    vector<pair<int, int>> ans;

    for (int i = 4; i <= n; i++)
    {
        int j = t - i;
        if (j < 1 || j > m)
            continue;
        ans.push_back({i, j});
    }

    ll result = 0;

    for (int i = 0; i < ans.size(); i++)
    {
        int a = ans[i].first;
        int b = ans[i].second;

        ll x = nCr(n, a);
        ll y = nCr(m, b);

        result = result + (x * y);
    }

    cout << result << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}