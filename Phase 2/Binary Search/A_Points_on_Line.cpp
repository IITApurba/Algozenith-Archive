#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;

void solve()
{
    int n, d;
    cin >> n >> d;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int lim = arr[i] + d;
        int extra = upper_bound(arr + i + 1, arr + n, lim) - (arr + i + 1);

        ans += 1LL * extra * (extra - 1) / 2;
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