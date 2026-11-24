#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector<int> arr;

void swapVal(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void reverseRange(int l, int r)
{
    while (l < r)
    {
        swapVal(arr[l], arr[r]);
        l++;
        r--;
    }
}

void solve()
{
    cin >> n;
    arr.resize(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int pivot = -1;
    for (int i = n - 2; i >= 0; i--)
        if (arr[i] < arr[i + 1])
        {
            pivot = i;
            break;
        }

    if (pivot != -1)
    {
        int replace_idx = pivot + 1;
        for (int i = pivot + 1; i < n; i++)
            if (arr[pivot] < arr[i])
                replace_idx = i;

        swapVal(arr[pivot], arr[replace_idx]);
    }

    reverseRange(pivot + 1, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
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