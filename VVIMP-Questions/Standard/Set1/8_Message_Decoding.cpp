/*
  Problem : Message Decoding
  Link    : https://maang.in/problems/Message-Decoding-351
  Given   : A digit string s, where A=1, B=2, ..., Z=26.
  Find    : Number of ways to decode s, mod 1e9+7.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

string str;
int n;
int dp[100005];

int mod = 1e9 + 7;

int rec(int i)
{
    // base case
    if (i == n)
        return 1; // reached the end, so this is one valid decoding

    // pruning
    if (i > n)
        return 0;

    // cache check
    if (dp[i] != -1)
        return dp[i];

    // transition
    int ans = 0;

    if (str[i] != '0') // only decode if it doesn't start with '0'
    {
        // case 1: take 1 char
        ans = rec(i + 1);

        // case 2: take 2 chars if they form 10..26
        if (i + 1 < n)
        {
            int num = (str[i] - '0') * 10 + (str[i + 1] - '0');
            if (num <= 26)
                ans = (ans + rec(i + 2)) % mod;
        }
    }
    // if str[i] == '0', both cases are skipped and ans stays 0

    // save and return
    return dp[i] = ans;
}

void solve()
{
    cin >> str;
    n = str.length();

    memset(dp, -1, sizeof(dp));

    int ans = rec(0) % mod;

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