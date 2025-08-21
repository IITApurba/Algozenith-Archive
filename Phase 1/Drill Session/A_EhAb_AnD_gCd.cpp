#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll lcm(ll a, ll b)
{
    return (a * b) / __gcd(a, b);
}

void solve()
{
    int x;
    cin >> x;

    if (x % 2 == 0)
    {
        cout << x / 2 << " " << x / 2 << endl;
        cout << "GCD = " << __gcd(x / 2, x / 2) + lcm(x / 2, x / 2) << endl;
    }
    else
    {
        int x1 = (x - 1) / 2;
        int y1 = (x + 1) / 2;
        cout << x1 << " " << y1 << endl;

        cout << "GCD = " << __gcd(x1, y1) + lcm(x1, y1) << endl;
    }
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