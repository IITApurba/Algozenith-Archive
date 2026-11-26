#include <bits/stdc++.h>
using namespace std;

int MedianInMatrix(vector<vector<int>> &a)
{
    int n = a.size(), m = a[0].size();

    // search range: min is in the first column, max is in the last column
    int lo = INT_MAX, hi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        lo = min(lo, a[i][0]);
        hi = max(hi, a[i][m - 1]);
    }

    // median = element at position (n*m + 1) / 2 in sorted order
    int need = (n * m + 1) / 2;

    // find the smallest x with count(<= x) >= need
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;

        // count elements <= mid (each row is sorted)
        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += upper_bound(a[i].begin(), a[i].end(), mid) - a[i].begin();

        if (cnt >= need)
            hi = mid;       // mid could be the median, try smaller
        else
            lo = mid + 1;   // too few elements <= mid, go bigger
    }

    return lo;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    cout << MedianInMatrix(a) << "\n";

    return 0;
}