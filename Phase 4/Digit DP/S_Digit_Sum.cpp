#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int mod = 1e9 + 7;

string L, R;
int len, D;

int dp[10010][2][2][101];

int rec(int level, int tlo, int thi, int sumD)
{
    if (level == len)
        return (sumD == 0) ? 1 : 0;

    if (dp[level][tlo][thi][sumD] != -1)
        return dp[level][tlo][thi][sumD];

    int ans = 0;
    int low = (tlo) ? L[level] - '0' : 0;
    int high = (thi) ? R[level] - '0' : 9;

    for (int i = low; i <= high; i++)
    {
        int newTlo = tlo && (i == low);
        int newThi = thi && (i == high);
        int newSumD = (sumD + i) % D;

        ans += rec(level + 1, newTlo, newThi, newSumD);
        ans %= mod;
    }
    return dp[level][tlo][thi][sumD] = ans;
}
void solve()
{
    L = "1";
    cin >> R;
    cin >> D;

    // Making L and R of equal length
    int cnt = R.length() - L.length();
    string temp = "";
    while (cnt--)
        temp += "0";

    L = temp + L;

    len = R.length();

    memset(dp, -1, sizeof(dp));

    cout << rec(0, 1, 1, 0) << endl;
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