#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ans += a[i] * i - a[i] * (n - i - 1);
    }

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