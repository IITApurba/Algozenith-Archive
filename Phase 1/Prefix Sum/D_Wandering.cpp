#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;

    vector<ll> prefix(n);
    prefix[0] = a[0];
    for (ll i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + a[i];

    // debug(prefix);
    ll pos = 0;
    ll max_prefix = prefix[0];
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        max_prefix = max(max_prefix, prefix[i]);
        ans = max(ans, pos + max_prefix);
        pos += prefix[i];
    }

    cout << ans << '\n';
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