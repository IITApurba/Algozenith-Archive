#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int depth = 0; depth <= n; depth++)
        {
            if (dp[i][depth] == 0)
                continue;

            // If we place '('
            if (s[i] == '(' || s[i] == '?')
            {
                if (depth + 1 <= n)
                    dp[i + 1][depth + 1] = (dp[i + 1][depth + 1] + dp[i][depth]) % MOD;
            }

            // If we place ')'
            if ((s[i] == ')' || s[i] == '?') && depth > 0)
            {
                dp[i + 1][depth - 1] = (dp[i + 1][depth - 1] + dp[i][depth]) % MOD;
            }
        }
    }

    cout << dp[n][0] << "\n";
}

signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
