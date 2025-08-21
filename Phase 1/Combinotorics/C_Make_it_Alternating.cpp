#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
ll fact[1000001];

void precompute()
{
    fact[0] = 1;
    for (ll i = 1; i <= 1000000; i++)
        fact[i] = (fact[i - 1] * i) % mod;
}

void solve()
{
    string s;
    cin >> s;
    ll n = s.size();

    vector<ll> extra;
    for (ll i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            ll length = 1;
            i++;
            while (i < n && s[i] == s[i - 1])
            {
                i++;
                length++;
            }
            extra.push_back(length - 1);
            i--; // Important: adjust i since the outer loop will increment it
        }
    }

    ll sum = 0;
    ll prod = 1;
    for (ll i = 0; i < extra.size(); i++)
    {
        sum = (sum + extra[i]) % mod;
        prod = (prod * (extra[i] + 1)) % mod;
    }

    ll ok = (prod * fact[sum]) % mod;
    cout << sum << " " << ok << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    precompute();

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}