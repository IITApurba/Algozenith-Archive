#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n, m;
vector<vector<int>> g;
vector<int> vis;

void solve()
{
    cin >> n;
    m = n - 1;

    g.resize(n + 1);
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> ans;
    ans.resize(n + 1);

    for (int i = 1; i < g.size(); i++)
        ans[i] = g[i].size();

    int max_deg = 0;
    for (int i = 1; i < ans.size(); i++)
        max_deg = max(max_deg, ans[i]);

    cout << max_deg + 1 << endl;
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