#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n;
int t[1001];
int s[1001];
int x, k;

int taken[1001];

bool check(int level)
{
    int timetaken = 0;
    int itemtaken = 0;

    for (int i = 0; i < level; i++)
    {
        if (taken[i])
        {
            timetaken += t[i];
            itemtaken += 1;
        }
    }
    timetaken += t[level];
    itemtaken++;

    if (itemtaken <= x && itemtaken <= k)
        return 1;
    else
        return 0;
}

int rec(int level)
{
    // max skill i can make from [level...n-1]
    // level - > current item of [0...n-1]

    // pruning

    // basecase
    if (level == n)
        return 0;

    // compute
    // loop over choice
    // choice 1 : don't take this
    int ans = rec(level + 1);
    // choice 2 : take
    if (check(level))
    {
        // place change
        taken[level] = 1;
        // move
        ans = max(ans, s[level] + rec(level + 1)); // max in [level+1...n]
        // revert
        taken[level] = 0;
    }

    // return
}

void solve()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> t[i] >> s[i];

    cin >> x >> k;

    cout << rec(0) << endl;
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