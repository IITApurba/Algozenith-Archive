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
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> pi = KMP(S);

    for (int i = 1; i < N; i++)
    {
        int lenA = (i + 1) - pi[i];
        if ((i + 1) % lenA == 0 && (i + 1) / lenA > 1)
        {
            cout << (i + 1) << " " << (i + 1) / lenA << "\n";
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int test = 1; test <= T; test++)
    {
        cout << "Test case #" << test << "\n";
        solve();
        cout << "\n";
    }

    return 0;
}
