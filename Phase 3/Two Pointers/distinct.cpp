#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;

// Check DS
int freq[100100];
int dcnt = 0;

void solve()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // number of subarrays with at most k distinct elements
    int head = -1, tail = 0;

    int ans = 0;

    while (tail < n)
    {
        while (head + 1 < n && ((freq[arr[head + 1]] == 0 && dcnt < k) ||
                                (freq[arr[head + 1]] > 0 && dcnt <= k)))
        {
            head++;
            if (freq[arr[head]] == 0)
                dcnt++;

            freq[arr[head]]++;
        }

        int len = (head - tail + 1);

        ans += len * (len + 1) / 2;

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

    cout << "Answer: " << ans << endl;
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