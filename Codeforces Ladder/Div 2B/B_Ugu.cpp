#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < n; i++)
        s[i] = s[i] - '0';

    for (int i = n-1; i >=1; i--)
    {
        s[i] = s[i] ^ s[i - 1];
    }

    int ans = count(s.begin(), s.end(), 1) - 1;
    
    ans = max(ans, 0);

    cout << ans << endl;
    
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