#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

const int INF = 1e9;
int n, m;
string s, t;
int dp[1001][1001];
// int next_pos[26][1001]; // next_pos[char][index in t]

vector<vector<int>> next_pos;

void preprocessNextPos(const string &t)
{
    int m = t.size();

    next_pos.assign(26, vector<int>(m + 1));

    for (int c = 0; c < 26; ++c)
        next_pos[c][m] = m; // Beyond the end, char doesn't exist

    debug(next_pos);

    for (int i = m - 1; i >= 0; --i)
    {

        for (int c = 0; c < 26; ++c)
            next_pos[c][i] = next_pos[c][i + 1];

        next_pos[t[i] - 'a'][i] = i;
    }
}

int solveDP(int i, int j)
{
    if (i == n)
        return INF;
    if (j == m)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    // Option 1: skip s[i]
    int option1 = solveDP(i + 1, j);

    // Option 2: take s[i]
    int next_idx = next_pos[s[i] - 'a'][j];
    int option2 = (next_idx == m) ? 1 : 1 + solveDP(i + 1, next_idx + 1);

    return dp[i][j] = min(option1, option2);
}

void solve()
{
    cin >> s >> t;
    n = s.size();
    m = t.size();

    memset(dp, -1, sizeof(dp));
    preprocessNextPos(t);

    int ans = solveDP(0, 0);
    cout << (ans >= INF ? -1 : ans) << "\n";

    debug(next_pos);
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