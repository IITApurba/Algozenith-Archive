#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n;
string s;
void solve()
{
    cin >> s;
    n = s.size();
    vector<int> dp(n + 1);
    int sum[n + 1];

    dp[0] = 1;
    sum[0] = 1;
    int last[26];

    memset(last, 0, sizeof(last));

    for (int i = 1; i <= n; i++)
    {
        dp[i] = sum[i - 1];
        if (last[s[i - 1] - 'a'] > 0)
            dp[i] -= sum[last[s[i - 1] - 'a'] - 1];

        last[s[i - 1] - 'a'] = i;
        sum[i] = sum[i - 1] + dp[i];
    }

    cout << sum[n] << endl;
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