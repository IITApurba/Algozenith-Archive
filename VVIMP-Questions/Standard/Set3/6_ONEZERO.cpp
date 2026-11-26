#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, x, y;
vector<string> bin_str;
int dp[101][101][101];

vector<int> Z, O;

int num_zero(string s)
{
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
            count++;
    }
    return count;
}

int num_ones(string s)
{
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            count++;
    }
    return count;
}

int rec(int level, int zero, int one)
{
    if (level > n || zero > x || one > y)
        return -1e8;

    if (level == n)
        return 0;

    if (dp[level][zero][one] != -1)
        return dp[level][zero][one];

    int non_take = rec(level + 1, zero, one);

    int take = 1 + rec(level + 1, zero + Z[level], one + O[level]);

    int ans = max(take, non_take);

    return dp[level][zero][one] = ans;
}

void solve()
{
    cin >> n >> x >> y;

    bin_str.resize(n);
    Z.resize(n);
    O.resize(n);

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        bin_str[i] = s;

        Z[i] = num_zero(s);
        O[i] = num_ones(s);
    }

    memset(dp, -1, sizeof(dp));

    int ans = rec(0, 0, 0);

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}