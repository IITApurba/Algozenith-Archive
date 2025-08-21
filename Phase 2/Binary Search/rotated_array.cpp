#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;
vector<ll> a = {5, 7, 10, 2, 3};

bool check(int x)
{
    if (a[x] < a[0])
        return true;
    else
        return false;
}

void solve()
{
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