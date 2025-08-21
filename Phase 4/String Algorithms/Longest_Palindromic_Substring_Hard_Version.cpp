#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

class Manacher
{
public:
    vector<int> computeManacher(const string &s)
    {
        string t = "#";
        for (char c : s)
        {
            t += c;
            t += '#';
        }

        int n = t.size();
        vector<int> p(n, 0);
        int center = 0, right = 0;

        for (int i = 0; i < n; i++)
        {
            if (i < right)
                p[i] = min(right - i, p[2 * center - i]);

            while (i - (p[i] + 1) >= 0 && i + (p[i] + 1) < n && t[i - (p[i] + 1)] == t[i + (p[i] + 1)])
                p[i]++;

            if (i + p[i] > right)
            {
                center = i;
                right = i + p[i];
            }
        }

        return p;
    }
};

void solve()
{
    string s;
    cin >> s;

    vector<int> M = Manacher().computeManacher(s);

    int idx = 0, maxLength = 0;
    for (int i = 0; i < M.size(); i++)
    {
        if (M[i] > maxLength)
        {
            maxLength = M[i];
            idx = i;
        }
    }

    // cout << "Max Length: " << maxLength << "\n";

    // the string is from [idx - maxLength, idx + maxLength]
    string ans = "";
    ans = s.substr((idx - maxLength) / 2, maxLength);
    cout << ans << "\n";
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