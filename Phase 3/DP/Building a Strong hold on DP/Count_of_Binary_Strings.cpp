#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

int dp4[MAXN][5];

int rec4(int level, int state)
{
    if (state == 4)
        return 0;
    if (level == 0)
        return 1;
    if (dp4[level][state] != -1)
        return dp4[level][state];

    int ans = 0;
    if (state == 0)
    {
        ans = (rec4(level - 1, 0) + rec4(level - 1, 1)) % MOD;
    }
    else if (state == 1)
    {
        ans = (rec4(level - 1, 1) + rec4(level - 1, 2)) % MOD;
    }
    else if (state == 2)
    {
        ans = (rec4(level - 1, 0) + rec4(level - 1, 3)) % MOD;
    }
    else if (state == 3)
    {
        ans = (rec4(level - 1, 2) + rec4(level - 1, 4)) % MOD;
    }

    return dp4[level][state] = ans;
}

void solve()
{
    memset(dp4, -1, sizeof(dp4));

    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        cout << rec4(n, 0) << '\n';
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
