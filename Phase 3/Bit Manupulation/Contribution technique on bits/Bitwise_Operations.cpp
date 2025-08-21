#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
typedef long long ll;

void solve()
{
    vector<ll> bit[20];
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<ll> done(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (arr[i] & (1 << j))
                bit[j].push_back(i); // push in bit[i] all the index which have ith bit on.
        }
    }
    ll k = 19;
    while (k >= 0)
    { // Greedily increasing the value of every number, starting from the most significant digit
        if (bit[k].size())
        {
            ll x = bit[k][bit[k].size() - 1]; // taking a element which may or may not have the kth bit set as it might be changed.
            bit[k].pop_back();
            if (done[x] or !((1 << k) & arr[x])) // if it is already done or bit is not set then continue
                continue;
            done[x] = 1; // trying to increase the value as much as I can using the lower bits.
            for (int i = 0; i < k + 1; i++)
            {
                if (arr[x] & (1 << i)) // it bit is already set then continue
                    continue;
                while (bit[i].size())
                { // find a index which has this bet set, then apply the operation to increase the value of x.
                    ll y = bit[i][bit[i].size() - 1];
                    bit[i].pop_back();
                    if (done[y] or !((1 << i) & arr[y]))
                        continue;

                    ll temp = arr[y];
                    arr[y] = arr[y] & arr[x]; // because of this operation the set bit of arr[y] can be unset.
                    arr[x] |= temp;
                    break;
                }
            }
        }
        else
            k--;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += arr[i] * arr[i];
    cout << ans << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}