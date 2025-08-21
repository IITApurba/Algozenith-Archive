#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;

    ll tv = 2000000000, fv = 0;
    while (tv - fv > 1)
    {
        ll mid = (tv + fv) / 2;
        if (mid * (mid + 1) / 2 > n)
            tv = mid;
        else
            fv = mid;
    }

    cout << tv + (n - tv * (tv - 1) / 2) << endl;
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