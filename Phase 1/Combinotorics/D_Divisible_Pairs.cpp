#include <bits/stdc++.h>
// #include "debug.cpp"
using namespace std;

typedef long long ll;

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    ll ans = 0;

    vector<pair<ll, ll>> v;

    for (ll i = 0; i < n; i++)
        v.push_back({a[i] % x, a[i] % y});

    // debug(v);

    map<pair<ll, ll>, ll> mp;

    for (ll i = 0; i < n; i++)
    {
        ll xx = v[i].first;
        ll yy = v[i].second;

        pair<ll, ll> target = {(x - xx) % x, yy};

        ans += mp[target];
        mp[{xx, yy}]++;
    }

    // debug(mp);

    cout << ans << endl; 
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}