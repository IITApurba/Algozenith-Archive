#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, m;

vector<vector<int>> g;
vector<int> indeg;
vector<int> topo;

void khan()
{
    priority_queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
            q.push(-i);
    }
    while (!q.empty())
    {
        int cur = -q.top();
        q.pop();
        topo.push_back(cur);
        for (auto v : g[cur])
        {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(-v);
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    indeg.resize(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b]++;
    }

    khan();

    if (topo.size() != n)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        for (auto v : topo)
            cout << v << " ";
        cout << endl;
    }
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