#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n;
string s;
const int m = 1e5 + 7;

int cost[m];
int dp[m][4];

int rec(int level, int match)
{
    // base case
    if (match == 4)
        return 1e18;

    if (level == n)
        return 0;

    if (dp[level][match] != -1)
        return dp[level][match];

    // compute
    // option1 : Delete the current character
    int option1 = cost[level] + rec(level + 1, match);

    // option2 : Keep the current character
    int option2 = 0;
    if (s[level] == "hard"[match])
        option2 = rec(level + 1, match + 1);
    else
        option2 = rec(level + 1, match);

    // save and return
    return dp[level][match] = min(option1, option2);
}

void solve()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    memset(dp, -1, sizeof(dp));

    int ans = rec(0, 0);

    if (ans >= 1e18)
        cout << 0 << endl;
    else
        cout << ans << endl;
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