#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n, m;
vector<int> s, t;
int dp[1001][1001];
vector<int> lcs;

// Recursive DP function
int rec(int i, int j)
{
    if (i == n || j == m)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j])
        return dp[i][j] = 1 + rec(i + 1, j + 1);
    else
        return dp[i][j] = max(rec(i + 1, j), rec(i, j + 1));
}

// Reconstruct LCS from dp table
void gen(int i, int j)
{
    if (i == n || j == m)
        return;

    if (s[i] == t[j])
    {
        lcs.push_back(s[i]);
        gen(i + 1, j + 1);
    }
    else if (dp[i + 1][j] >= dp[i][j + 1])
    {
        gen(i + 1, j);
    }
    else
    {
        gen(i, j + 1);
    }
}

void solve()
{
    cin >> n >> m;
    s.resize(n);
    t.resize(m);

    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < m; i++)
        cin >> t[i];

    memset(dp, -1, sizeof(dp));

    int len = rec(0, 0);
    cout << len << endl;

    gen(0, 0);

    for (int x : lcs)
        cout << x << " ";
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}
