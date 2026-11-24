#include <bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, k;
vector<int> price;
vector<vector<vector<int>>> dp;

int rec(int level, int buy, int cap)
{
    if (level == n || cap == k)
        return 0;

    if (dp[level][buy][cap] != -1)
        return dp[level][buy][cap];

    int take, not_take;

    if (buy == 1)
    {
        // Buy
        take = -price[level] + rec(level + 1, 0, cap);
        not_take = rec(level + 1, 1, cap);
    }
    else
    {
        // Sell
        take = price[level] + rec(level + 1, 1, cap + 1);
        not_take = rec(level + 1, 0, cap);
    }

    return dp[level][buy][cap] = max(take, not_take);
}

int BuyAndSellStock()
{
    n = price.size();

    dp.assign(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));

    return rec(0, 1, 0);
}

signed main()
{
    IOS

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        price.resize(n);

        for (int i = 0; i < n; i++)
            cin >> price[i];

        cout << BuyAndSellStock() << "\n";
    }

    return 0;
}
