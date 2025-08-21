#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

vector<int> manacher(const string &s)
{
    int n = s.size();
    vector<int> p(n, 0); // p[i] = radius of palindrome centered at i (including center)

    int center = 0, right = 0;

    for (int i = 0; i < n; i++)
    {
        if (i < right)
            p[i] = min(right - i, p[2 * center - i]);

        // Expand around center i
        while (i - (p[i] + 1) >= 0 && i + (p[i] + 1) < n && s[i - (p[i] + 1)] == s[i + (p[i] + 1)])
            p[i]++;

        // Update center and right boundary
        if (i + p[i] > right)
        {
            center = i;
            right = i + p[i];
        }
    }

    return p;
}

void solve()
{
    string s;
    cin >> s;

    // Preprocess the string: insert '#' between and around characters
    string t = "#";
    for (char c : s)
    {
        t += c;
        t += '#';
    }

    vector<int> p = manacher(t);
    p[0] = 0;
    p[p.size() - 1] = 0;

    for (int i = 0; i < p.size(); i++)
        cout << p[i] << " ";
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
