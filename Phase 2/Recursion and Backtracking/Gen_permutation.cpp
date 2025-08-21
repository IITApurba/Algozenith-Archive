#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
vector<int> cur_perm;
map<int, int> mp;
int n;
vector<vector<int>> all_sol;

void rec(int level)
{
    debug(level, mp, cur_perm);
    if (level == n)
    {
        all_sol.push_back(cur_perm);
        return;
    }

    for (auto v : mp)
    {
        if (v.second != 0)
        {
            mp[v.first]--;
            cur_perm.push_back(v.first);
            rec(level + 1);
            cur_perm.pop_back();
            mp[v.first]++;
        }
    }
}

void solve()
{
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        mp[a[i]]++;

    rec(0);

    debug(all_sol);
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