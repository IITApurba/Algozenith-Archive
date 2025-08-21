#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;

vector<vector<int>> g;
vector<int> vis;

void dfs(int node, int comp_no)
{
    vis[node] = comp_no;

    for (auto v : g[node])
        if (!vis[v])
            dfs(v, comp_no);
}

void solve()
{
    int n, m;
    cin >> n >> m;

    g.resize(n + 1);
    vis.assign(n + 1, 0);

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    int num_comp = 0;

    // Statergy to explore everything (✿◠‿◠)
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            num_comp++;
            dfs(i, num_comp);
        }

    cout << "Number of Components = " << num_comp << endl;

    // Now using the visited array we can answer the (x,y) quiries too
    int quries;
    cin >> quries;
    while (quries--)
    {
        int x, y;
        cin >> x >> y;

        if(vis[x]==vis[y])
            cout << "Yes connected" << endl;
        else
            cout << "Not connected" << endl;
    }
    

    vector<vector<int>> components;
    components.resize(num_comp + 1);

    for (int i = 1; i <= n; i++)
    {
        cout << i << " : " << vis[i] << endl;
        components[vis[i]].push_back(i);
    }

    debug(components);

    for (int i = 1; i < components.size(); i++)
        cout << "Size " << i << " = " << components[i].size() << endl;
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