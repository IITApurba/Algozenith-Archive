#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

multiset<int> at;
vector<vector<int>> g;
vector<int> val, ans;

void insert(int x)
{
    at.insert(x);
}

void remove(int x)
{
    at.erase(at.find(x));
}

// Sample query: count of values ≤ val[node] in multiset
int query(int x)
{
    int ans = 1e9;
    auto it = at.lower_bound(x);

    if (it != at.end())
        ans = min(ans, abs(*it - x));

    if (it != at.begin())
    {
        it--;
        ans = min(ans, abs(*it - x));
    }
    return ans;
}

void dfs(int node, int par)
{
    ans[node] = query(val[node]);
    insert(val[node]);

    for (auto v : g[node])
    {
        if (v != par)
        {
            dfs(v, node);
        }
    }

    remove(val[node]); // backtrack
}

void solve()
{
    int n;
    cin >> n;

    val.resize(n + 1);
    g.assign(n + 1, {});
    ans.resize(n + 1);

    for (int i = 1; i <= n; ++i)
        cin >> val[i];

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0); // assuming root is 1

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";

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
