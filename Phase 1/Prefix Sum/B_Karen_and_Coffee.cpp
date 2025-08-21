#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k, q;
    cin >> n >> k >> q;

    ll m = 200001;
    vector<ll> a(m, 0);

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        a[l]++;
        a[r + 1]--;
    }

    for (int i = 1; i < m; i++)
        a[i] += a[i - 1];

    for (int i = 0; i < m; i++)
        if (a[i] >= k)
            a[i] = 1;
        else
            a[i] = 0;

    for (int i = 1; i < m; i++)
        a[i] += a[i - 1];

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << a[r] - a[l - 1] << '\n';
    }
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