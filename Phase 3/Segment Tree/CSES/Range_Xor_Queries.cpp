#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    vector<int> prefix_xor(n + 1, 0);
    for (int i = 1; i <= n; i++)
        prefix_xor[i] = prefix_xor[i - 1] ^ arr[i];

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << (prefix_xor[r] ^ prefix_xor[l - 1]) << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}