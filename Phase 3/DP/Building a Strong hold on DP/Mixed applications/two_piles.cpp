#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int a, b;

int dp[1001][1001];

int rec(int x, int y)
{
    if (x == 0 && y == 0)
        return 0;

    if (dp[x][y] != -1)
        return dp[x][y];

    int win = 0;
    for (int i = 1; i <= x; i++)
    {
        if (dp[x - i][y] == 0)
        {
            win = 1;
        }
    }

    for (int i = 1; i <= y; i++)
    {
        if (dp[x][y - i] == 0)
        {
            win = 1;
        }
    }

    for (int i = 1; i <= min(x, y); i++)
    {
        if (rec(x - i, y - i) == 0)
        {
            win = 1;
        }
    }

    return dp[x][y] = win;
}

void solve()
{
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    int ans = rec(a, b);
    if (ans == 0)
        cout << "Second" << endl;
    else
        cout << "First" << endl;
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