#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, k;

bool check(ll mid)
{
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += min(mid / i, m);
    }

    if(cnt>=k)
        return true;
    else
        return false;
}

void solve()
{
    cin >> n >> m >> k;
    ll ans = -1;

    ll lo = 0, hi = n*m;

    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
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