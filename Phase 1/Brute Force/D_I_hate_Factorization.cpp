#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll power(ll base, int exp)
{
    ll result = 1;
    for (int i = 0; i < exp; i++)
    {
        result *= base;
    }
    return result;
}

void solve()
{
    ll x;
    cin >> x;

    // Hash map to store b^5 values
    unordered_map<ll, int> power_map;

    // Precompute b^5 for all b in the range [-1000, 1000]
    for (int b = -1000; b <= 1000; b++)
    {
        power_map[power(b, 5)] = b;
    }

    // Iterate over a and check if (a^5 - x) exists in the map
    for (int a = -1000; a <= 1000; a++)
    {
        ll a5 = power(a, 5);
        ll b5 = a5 - x; // Check if b^5 = a^5 - x exists
        if (power_map.count(b5))
        {
            int b = power_map[b5];
            cout << a << " " << b << endl;
            return;
        }
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
