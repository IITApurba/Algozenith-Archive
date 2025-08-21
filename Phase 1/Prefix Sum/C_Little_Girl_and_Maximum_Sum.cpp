#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> prefix(n, 0);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        prefix[l]++;
        if (r + 1 < n)
            prefix[r + 1]--;
    }

    for (int i = 1; i < n; i++)
        prefix[i] += prefix[i - 1];

    sort(a.begin(), a.end());
    sort(prefix.begin(), prefix.end());

    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += a[i] * prefix[i];

    cout << ans << endl;
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