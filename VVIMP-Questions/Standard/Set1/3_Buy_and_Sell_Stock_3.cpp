/*
  Problem : Buy and Sell Stock 3
  Link    : https://maang.in/problems/Buy-and-Sell-Stock-3-278
  Given   : Stock prices for N days; at most 2 transactions, hold one stock at a time.
  Find    : Maximum profit.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

const int Max_N = 1e5 + 1;

int n;
int dp[Max_N][2][3];
vector<int> price;

int rec(int level, int buy, int cap)
{
    if (level == n || cap == 2)
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
        // Sell: one transaction completed
        take = price[level] + rec(level + 1, 1, cap + 1);
        not_take = rec(level + 1, 0, cap);
    }

    return dp[level][buy][cap] = max(take, not_take);
}

int BuyAndSellStock()
{
    n = price.size();

    memset(dp, -1, sizeof(dp));

    return rec(0, 1, 0);
}

signed main()
{
    IOS

        int t;
    cin >> t;

    while (t--)
    {
        cin >> n;

        price.resize(n);

        for (int i = 0; i < n; i++)
            cin >> price[i];

        cout << BuyAndSellStock() << "\n";
    }

    return 0;
}
