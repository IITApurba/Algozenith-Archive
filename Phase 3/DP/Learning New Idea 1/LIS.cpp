#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    int inst[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> lis;

    for (int i = 0; i < n; i++)
    {
        if (lis.empty() || lis.back() < arr[i])
        {
            lis.push_back(arr[i]);
            inst[i] = lis.size() - 1;
        }
        else
        {
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            *it = arr[i];
            inst[i] = it - lis.begin();
        }

        cout << i << ": ";
        for (auto v : lis)
            cout << v << ", ";
        cout << "\n";
    }

    vector<int> final;
    int curlen = lis.size() - 1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (inst[i] == curlen)
        {
            final.push_back(arr[i]);
            curlen--;
        }
    }

    reverse(final.begin(), final.end());

    for (auto v : final)
    {
        cout << v << " ";
    }
    cout << endl;
    cout << lis.size() << endl;
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
