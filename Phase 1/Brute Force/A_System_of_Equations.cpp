#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll count = 0;
    ll k = min(n, m);

    for (ll i = 0; i <= k; i++)
        for (ll j = 0; j <= k; j++)
            if (i * i + j == n && j * j + i == m)
                count++;

    cout << count << endl;
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