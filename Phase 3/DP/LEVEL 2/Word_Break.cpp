#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

string s;
unordered_set<string> dict;
int n;
vector<int> dp;

bool rec(int index)
{
    if (index == s.size())
        return true;

    if (dp[index] != -1)
        return dp[index];

    for (const string &word : dict)
    {
        int len = word.length();
        
        if (index + len <= s.length() && s.substr(index, len) == word)
        {
            if (rec(index + len))
                return dp[index] = true;
        }
    }

    return dp[index] = false;
}

void solve()
{
    cin >> n;
    cin >> s;

    dict.clear();

    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        dict.insert(word);
    }

    dp.assign(s.size(), -1);

    if (rec(0))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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
