#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
#define INF 1e9
int n, k;
int arr[1001];
int dp[1001][1001];

// This code solves a problem where we are given an array `arr` of size `n` and an integer `k`.
// The goal is to partition the array into exactly `k` non-empty contiguous subarrays such that
// the sum of the minimum values of each subarray is maximized.

// The function `rec(i, x)` is a recursive function that computes the maximum sum of minimum values
// of `x` subarrays using the first `i+1` elements of the array. It uses dynamic programming
// with memoization to avoid redundant calculations.

// The `dp` array is used to store the results of subproblems, where `dp[i][x]` represents the
// maximum sum of minimum values of `x` subarrays using the first `i+1` elements.

// The `solve` function reads input values, initializes the `dp` array with `-1` (indicating
// uncomputed states), and calls the recursive function `rec` to compute the result for the given
// input. The result is then printed for each test case.

int rec(int i, int x)
{ //->max
    // pruning
    if (i >= 0 && x < 0)
        return -INF;
    // basecase
    if (i == -1)
    {
        if (x == 0)
            return 0;
        return -INF;
    }

    // save and check
    if (dp[i][x] != -1)
        return dp[i][x];

    // compute
    int ans = -INF;
    int minval = arr[i];
    for (int j = i; j >= 0; j--)
    {
        minval = min(minval, arr[j]);
        ans = max(ans, minval + rec(j - 1, x - 1));
    }

    // save and return
    return dp[i][x] = ans;
}

void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    memset(dp, -1, sizeof(dp));

    cout << rec(n - 1, k) << endl;
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