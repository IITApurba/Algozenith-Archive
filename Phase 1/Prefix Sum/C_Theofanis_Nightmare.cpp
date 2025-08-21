#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    long long suf[n + 1] = {0};
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = n - 1; i >= 0; i--)
        suf[i] = suf[i + 1] + arr[i];

    long long ans = suf[0];

    for (int i = 1; i < n; i++)
        if (suf[i] > 0)
            ans += suf[i];

    cout << ans << "\n";
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