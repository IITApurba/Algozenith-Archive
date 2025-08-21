#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int head = -1, tail = 0;

    int cnt0 = 0;
    int ans = 0;

    while (tail < n)
    {
        while (head + 1 < n && ((arr[head + 1] == 0 && cnt0 < k) || (arr[head + 1] == 1 && cnt0 <= k)))
        {
            head++;

            if (arr[head] == 0)
                cnt0++;
        }

        ans = max(ans, head - tail + 1);

        if (tail <= head)
        {
            if (arr[tail] == 0)
                cnt0--;
            tail++;
        }
        //Don't Think add this statment in all your questions!!!
        else
        {
            tail++;
            head = tail - 1;
        }
    }

    cout << ans << endl;
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