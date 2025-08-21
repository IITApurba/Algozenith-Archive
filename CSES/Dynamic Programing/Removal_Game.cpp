#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> a;
vector<vector<int>> dp;
vector<int> prefix;

int sum(int i, int j)
{
    return prefix[j + 1] - prefix[i];
}

int rec(int i, int j)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int pickLeft = a[i] + (sum(i + 1, j) - rec(i + 1, j));
    int pickRight = a[j] + (sum(i, j - 1) - rec(i, j - 1));

    return dp[i][j] = max(pickLeft, pickRight);
}

void solve()
{
    int n;
    cin >> n;
    a.resize(n);
    for (int &x : a)
        cin >> x;

    // Precompute prefix sums
    prefix.resize(n + 1);
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + a[i];

    dp.assign(n, vector<int>(n, -1));
    cout << rec(0, n - 1) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t; // Uncomment if multiple test cases
    while (t--)
        solve();
    return 0;
}
