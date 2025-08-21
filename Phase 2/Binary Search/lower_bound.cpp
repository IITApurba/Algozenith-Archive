#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;
vector<ll> a = {1, 2, 8, 8, 17, 20, 91};
// a = {1, 2, 8, 8, 17, 20, 91}
// i = {0, 1, 2, 3, 4, 5, 6, 7}

int x;

bool check(int mid)
{
    if (a[mid] >= x)
        return true;
    else
        return false;
}

void solve()
{
    cin >> x;
    int n = a.size();
    int lo = 0, hi = n - 1;
    int ans = n;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;

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

    debug(ans);
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