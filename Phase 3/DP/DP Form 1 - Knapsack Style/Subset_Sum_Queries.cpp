#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
#define endl '\n'
int n, target;
int x[105];          
int dp[105][100100]; 

int rec(int level, int left)
{
    if (left < 0)
        return 0;
    if (level == n)
        return (left == 0) ? 1 : 0;

    if (dp[level][left] != -1)
        return dp[level][left];

    int ans = 0;

    if (rec(level + 1, left) == 1)
        ans = 1;
    else if (rec(level + 1, left - x[level]) == 1)
        ans = 1;

    return dp[level][left] = ans;
}

void printset(int level, int left)
{
    if (level == n || left < 0)
        return;

    if (rec(level + 1, left) == 1) 
        printset(level + 1, left);
    else if (rec(level + 1, left - x[level]) == 1) 
    {
        cout << level << " ";
        printset(level + 1, left - x[level]);
    }
}

void solve()
{
    cin >> n;
    int q;
    cin >> q;

    for (int i = 0; i < n; i++)
        cin >> x[i];

    while (q--)
    {
        cin >> target;
        memset(dp, -1, sizeof(dp));

        if (rec(0, target))
        {
            printset(0, target);
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
