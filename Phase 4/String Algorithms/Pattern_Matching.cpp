#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

string p, t;
int n, m;
int kmp[1000005];
string combined;

void KMP()
{
    int i = 0, j = -1;

    kmp[0] = -1;
    while (i < combined.size())
    {
        while (j != -1 && combined[i] != combined[j])
            j = kmp[j];

        i++;
        j++;
        kmp[i] = j;
    }
}

void solve()
{
    cin >> p >> t;
    n = p.length();
    m = t.length();

    combined = p + "#" + t;

    debug(combined);

    KMP();

    // index of the first occurrence of p in t
    for (int i = 1; i <= combined.size(); i++)
    {
        if (kmp[i] == n)
        {
            cout << "Pattern found at index " << i - 2 * n << endl;
        }
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