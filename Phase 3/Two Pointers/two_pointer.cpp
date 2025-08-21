#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // pointers
    int head = -1, tail = 0;

    // check DS
    int cnt0 = 0;

    int ans = 0;

    while (tail < n)
    {
        while (head + 1 < n && ((arr[head + 1] == 0 && cnt0 < k) || (arr[head + 1] == 1 && cnt0 <= k)))
        {
            head++;
            // maintain DS
            if (arr[head] == 0)
                cnt0++;
        }
        // Process answer
        ans = max(ans, head - tail + 1);

        //if couting all the subarrays
        // ans+= (head - tail + 1);

        if (tail <= head)
        {
            if (arr[tail] == 0)
                cnt0--;
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