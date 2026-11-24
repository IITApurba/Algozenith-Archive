#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // leftMax[i] = tallest bar from index 0 to i
    vector<int> leftMax(n);
    leftMax[0] = a[0];
    for (int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i - 1], a[i]);

    // rightMax[i] = tallest bar from index i to n-1
    vector<int> rightMax(n);
    rightMax[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rightMax[i] = max(rightMax[i + 1], a[i]);

    // water on top of bar i = min(left wall, right wall) - its own height
    int water = 0;
    for (int i = 0; i < n; i++)
        water += min(leftMax[i], rightMax[i]) - a[i];

    cout << water << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}