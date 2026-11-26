#include <bits/stdc++.h>
using namespace std;

string s;
int n, len;
unordered_set<string> dict;
int maxWordLen;
int dp[305];        // dp[i] = can s[i..] be segmented (-1 = not computed)

int rec(int i)
{
    // base case: whole string segmented
    if (i == len)
        return 1;

    // cache check
    if (dp[i] != -1)
        return dp[i];

    // transition: try every word length starting at i
    int ans = 0;
    for (int L = 1; L <= maxWordLen && i + L <= len; L++)
    {
        // s[i .. i+L-1] is a word AND the rest can be segmented
        if (dict.count(s.substr(i, L)) && rec(i + L))
        {
            ans = 1;
            break;
        }
    }

    // save and return
    return dp[i] = ans;
}

void solve()
{
    cin >> n;
    cin >> s;
    len = s.size();

    dict.clear();
    maxWordLen = 0;
    for (int i = 0; i < n; i++)
    {
        string w;
        cin >> w;
        dict.insert(w);
        maxWordLen = max(maxWordLen, (int)w.size());
    }

    memset(dp, -1, sizeof(dp));

    cout << (rec(0) ? "Yes" : "No") << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}