#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

void solve()
{
    int n, t;
    cin >> n >> t;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int left = 0;
    int right = n - 1;

    int index1 = -1, index2 = -1;

    while (left < right)
    {
        if (a[left] + a[right] == t)
        {
            index1 = left;
            index2 = right;
            break;
        }
        else if (a[left] + a[right] < t)
        {
            left++;
        }
        else if (a[left] + a[right] > t)
        {
            right--;
        }
    }


    cout << a[left] << " " << a[right] << endl;
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