#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

class KMP
{
public:
    vector<int> computePrefix(const string &s)
    {
        int n = s.length();
        vector<int> kmp(n + 1);
        kmp[0] = -1;
        int i = 0, j = -1;

        while (i < n)
        {
            while (j != -1 && s[i] != s[j])
                j = kmp[j];
            i++;
            j++;
            kmp[i] = j;
        }

        return kmp;
    }
};

void solve()
{
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