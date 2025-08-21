#include <bits/stdc++.h>
// #include "debug.cpp"
using namespace std;

typedef long long ll;

vector<vector<int>> g;
vector<int> vis;

void solve()
{
    int n, m;
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

    // debug(g);

    vector<int> ans;
    ans.resize(n+1);

    for (int i = 1; i < g.size(); i++)
    {
        ans[i] = g[i].size();
    }

    // debug(ans);

    int max_degree=0;
    for (int i = 1; i < ans.size(); i++)
    {
        max_degree = max(max_degree, ans[i]);
    }

    cout << max_degree + 1 << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}