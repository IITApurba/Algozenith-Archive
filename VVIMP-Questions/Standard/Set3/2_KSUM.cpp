#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;

    // first[r] = smallest prefix length whose sum % k == r  (-1 = not seen yet)
    vector<int> first(k, -1);
    first[0] = 0;       // empty prefix (length 0) has sum 0

    int pre = 0, ans = 0;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        // prefix sum mod k, kept in [0, k-1] even for negatives
        pre = ((pre + x) % k + k) % k;

        if (first[pre] == -1)
            first[pre] = i;                    // first time seeing this remainder
        else
            ans = max(ans, i - first[pre]);    // same remainder: sum in between is divisible by k
    }

    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}