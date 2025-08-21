#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

vector<int> z_algo(const string &s)
{

    int n = s.size();
    vector<int> z(n);

    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

vector<int> getpos(string text, string pattern)
{
    string s = pattern + "#" + text;

    vector<int> z = z_algo(s);
    vector<int> pos;

    for (int i = 0; i < z.size(); i++)
    {
        if (z[i] == pattern.size())
        {
            pos.push_back(i - pattern.size() - 1);
        }
    }
    return pos;
}

void solve()
{
    string text = "ababcababcabc";
    string pattern = "abc";

    debug(text);
    debug(pattern);

    vector<int> positions = getpos(text, pattern);

    cout << "Pattern found at positions: ";
    for (int pos : positions)
        cout << pos << " ";
    cout << "\n";

    // Additional test cases
    text = "aaaaa";
    pattern = "aa";

    debug(text);
    debug(pattern);

    positions = getpos(text, pattern);
    
    cout << "Pattern found at positions (aaaaa, aa): ";
    for (int pos : positions)
        cout << pos << " ";
    cout << "\n";

    text = "abcabcabc";
    pattern = "abcabc";

    debug(text);
    debug(pattern);

    positions = getpos(text, pattern);
    cout << "Pattern found at positions (abcabcabc, abcabc): ";
    for (int pos : positions)
        cout << pos << " ";
    cout << "\n";

    text = "xyz";
    pattern = "a";

    debug(text);
    debug(pattern);

    positions = getpos(text, pattern);
    cout << "Pattern found at positions (xyz, a): ";
    for (int pos : positions)
        cout << pos << " ";
    cout << "\n";
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