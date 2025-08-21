#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n, m;
string s, t;
int dp[3003][3003];

int rec(int i, int j)
{
    // base case
    if (i == n || j == m)
        return 0;

    // cache check
    if (dp[i][j] != -1)
        return dp[i][j];

    // compute
    int ans = 0;
    if (s[i] == t[j])
        ans = 1 + rec(i + 1, j + 1);
    else
        ans = max(rec(i + 1, j), rec(i, j + 1));

    return dp[i][j] = ans;

}
// printing the solution
void print(int i, int j)
{
    if (i == n || j == m)
        return;

    if (s[i] == t[j])
    {
        cout << s[i];
        print(i + 1, j + 1);
    }
    else
    {
        if (dp[i + 1][j] > dp[i][j + 1])
            print(i + 1, j);
        else
            print(i, j + 1);
    }
}

void solve()
{
    cin >> s >> t;

    n = s.size();
    m = t.size();

    memset(dp, -1, sizeof(dp));

    int ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans = max(ans, rec(i, j));

    // rec(0, 0);

    print(0, 0);
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}