#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

const int INF = 1000000000000000000LL; // 1e18
int n;
int arr[101001];
int max_product[101001];
int min_product[101001];

// rec(i, +1) = maximum product of any subarray that ends exactly at index i
// rec(i, -1) = minimum product of any subarray that ends exactly at index i

int rec(int i, int sign)
{
    // (we should never actually call rec(-1, ...), but guard just in case)
    if (i < 0)
        return 1;

    // BASE CASE: at index 0, both “max ending at 0” and “min ending at 0” are arr[0].
    if (i == 0)
    {
        if (sign == +1)
        {
            max_product[0] = arr[0];
            return arr[0];
        }
        else
        {
            min_product[0] = arr[0];
            return arr[0];
        }
    }

    // CACHE CHECK
    if (sign == +1 && max_product[i] != -INF)
    {
        return max_product[i];
    }
    if (sign == -1 && min_product[i] != +INF)
    {
        return min_product[i];
    }

    // First, ensure we have “max ending at i-1” and “min ending at i-1” computed:
    int prev_min = rec(i - 1, -1);
    int prev_max = rec(i - 1, +1);

    // Start ans = arr[i], then combine with prev_min/prev_max
    int ans = arr[i];
    if (sign == +1)
    {
        // We want the maximum‐ending‐at‐i:
        ans = max({ans,
                   arr[i] * prev_max,
                   arr[i] * prev_min});
        max_product[i] = ans;
        return ans;
    }
    else
    {
        // We want the minimum‐ending‐at‐i:
        ans = min({ans,
                   arr[i] * prev_max,
                   arr[i] * prev_min});
        min_product[i] = ans;
        return ans;
    }
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        max_product[i] = -INF;
        min_product[i] = +INF;
    }

    // We’ll accumulate the global maximum over all “max ending at i”:
    int global_max = arr[0];

    for (int i = 0; i < n; i++)
    {
        int val = rec(i, +1); // maximum product of subarray ending at i
        global_max = max(global_max, val);
    }

    cout << global_max << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
