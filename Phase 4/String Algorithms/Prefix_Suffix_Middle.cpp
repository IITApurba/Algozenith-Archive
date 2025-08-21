#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

vector<int> KMP(const string &s)
{
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> pi = KMP(s);
    int len = pi[n - 1];

    set<int> occur;
    for (int i = 1; i < n - 1; i++)
        occur.insert(pi[i]);

    while (len > 0)
    {
        if (occur.count(len))
        {
            cout << s.substr(0, len) << '\n';
            return;
        }
        len = pi[len - 1];
    }

    cout << -1 << '\n';
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
