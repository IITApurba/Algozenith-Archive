#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n;
string s;

int dp[100005][4][4];

int rec(int i, int prev, int first)
{
    if (i == n)
        if (prev == first && n != 1)
            return 0;
        else
            return 1;

    if (prev != -1 && dp[i][prev][first] != -1)
        return dp[i][prev][first];

    int ans = 0;

    if (s[i] == '?')
    {
        for (int ch = 0; ch < 4; ch++)
        {
            if (ch == prev)
                continue;
            if (i == 0)
                ans += rec(i + 1, ch, ch);
            else
                ans += rec(i + 1, ch, first);
        }
    }
    else
    {
        if (s[i] - 'A' == prev)
            return 0;
        else if (i == 0)
            ans += rec(i + 1, s[i] - 'A', s[i] - 'A');
        else
            ans += rec(i + 1, s[i] - 'A', first);
    }

    if (prev != -1)
        dp[i][prev][first] = ans;
    return ans;
}

string temp;
// generate best lexo string
//  0 -> A, 1 -> B, 2 -> C, 3 -> D
void sol(int i, int prev, int first)
{
    if (i == n)
        return;

    if (s[i] == '?')
    {
        for (int ch = 0; ch < 4; ch++)
        {
            if (ch == prev)
                continue;
            if (rec(i + 1, ch, (i == 0 ? ch : first)) > 0)
            {
                temp += char('A' + ch);
                sol(i + 1, ch, (i == 0 ? ch : first));
                return;
            }
        }
    }
    else
    {
        if (s[i] - 'A' == prev)
            return;
        
        temp += s[i];
        sol(i + 1, s[i] - 'A', (i == 0 ? s[i] - 'A' : first));
    }
}

void solve()
{
    cin >> n >> s;

    memset(dp, -1, sizeof dp);

    int ans = rec(0, -1, -1);
    cout << ans << '\n';
    if (ans > 0)
    {
        sol(0, -1, -1);
        cout << temp << '\n';
    }
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
