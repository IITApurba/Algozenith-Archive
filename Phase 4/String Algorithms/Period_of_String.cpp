#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

string s;
int n;
int kmp[1000005];

void KMP(string &s)
{
    int i = 0, j = -1;

    kmp[0] = -1;
    while (i < s.size())
    {
        while (j != -1 && s[i] != s[j])
            j = kmp[j];

        i++;
        j++;
        kmp[i] = j;
    }
}

void solve()
{
    cin >> s;
    n = s.length();

    KMP(s);

    int len = kmp[n];

    int period = n - len;

    cout << "Normal Period" << endl;

    if (n % period == 0)
    {
        cout << "The period of the string is " << period << endl;
    }
    else
    {
        cout << "The period of the string is " << n << endl;
    }

    cout << endl;
    cout << "Extended Period" << endl;
    cout << "The period of the string is " << period << endl;
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