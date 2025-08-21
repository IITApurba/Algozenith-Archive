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
    int inserted_at[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> lis;
    for (int i = 0; i < n; i++)
    {
        if (lis.empty() || lis.back() < arr[i])
        {
            lis.push_back(arr[i]);
            inserted_at[i] = lis.size();
        }
        else
        {
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            *it = arr[i];
            inserted_at[i] = it - lis.begin() + 1;
        }
    }

    int curlen = lis.size();

    vector<int> final_lis;

    for (int i = n - 1; i >= 0; i--)
    {
        if (inserted_at[i] == curlen)
        {
            final_lis.push_back(arr[i]);
            curlen--;
        }
    }

    reverse(final_lis.begin(), final_lis.end());

    cout << "Length of LIS: " << final_lis.size() << "\n";
    cout << "LIS: ";
    for (auto i : final_lis)
        cout << i << " ";
    cout << "\n";
    
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