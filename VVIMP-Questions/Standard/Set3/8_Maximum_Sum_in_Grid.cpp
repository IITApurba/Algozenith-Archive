#include <bits/stdc++.h>
using namespace std;

#define int long long

// max subarray sum (works even if all numbers are negative)
int kadane(vector<int> &arr)
{
    int best = arr[0], cur = 0;
    for (int x : arr)
    {
        cur = max(x, cur + x);      // extend the current subarray or start fresh at x
        best = max(best, cur);
    }
    return best;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    // make rows the smaller side, so the O(n^2 * m) loop is cheaper
    if (n > m)
    {
        vector<vector<int>> b(m, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                b[j][i] = a[i][j];
        a = b;
        swap(n, m);
    }

    int ans = LLONG_MIN;

    for (int top = 0; top < n; top++)
    {
        // col[j] = sum of column j from row top to row bot
        vector<int> col(m, 0);

        for (int bot = top; bot < n; bot++)
        {
            // add row bot to the column sums
            for (int j = 0; j < m; j++)
                col[j] += a[bot][j];

            // best left..right range for this top..bot strip
            ans = max(ans, kadane(col));
        }
    }

    cout << ans << "\n";
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