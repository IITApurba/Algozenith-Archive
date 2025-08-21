#include <bits/stdc++.h>
using namespace std;

#define int long long

int freq[100100];

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    memset(freq, 0, sizeof(freq));

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int head = -1, tail = 0;
    int dcnt = 0;
    int ans = 0;

    while (tail < n)
    {
        while (head + 1 < n &&
               ((freq[arr[head + 1]] == 0 && dcnt < k) ||
                (freq[arr[head + 1]] > 0 && dcnt <= k)))
        {
            head++;
            if (freq[arr[head]] == 0)
                dcnt++;
            freq[arr[head]]++;
        }

        ans += head - tail + 1;

        if (tail <= head)
        {
            freq[arr[tail]]--;
            if (freq[arr[tail]] == 0)
                dcnt--;

            tail++;
        }
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
    while (t--)
        solve();

    return 0;
}
