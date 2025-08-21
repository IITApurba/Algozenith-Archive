#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int ways(int level, int final)
{

    // pruning
    if (level > final)
        return 0;

    // BASE CASE
    if (level == final)
        return 1; // generally in counting problem its always 1

    int ans = 0;

    // choice... 1,2,3 ways
    ans += ways(level + 1, final);
    ans += ways(level + 2, final);
    ans += ways(level + 3, final);

    return ans;
}

void solve()
{
    int n;
    cin >> n;

    int ans = ways(1, n);

    cout << ans << endl;
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