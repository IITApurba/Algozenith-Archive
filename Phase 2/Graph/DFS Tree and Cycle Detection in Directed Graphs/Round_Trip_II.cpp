#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, m;
bool is_cycle = 0;

vector<vector<int>> g;
vector<int> col;
vector<int> parent;
vector<int> any_cycle;

void dfs(int node, int par)
{
    parent[node] = par;
    col[node] = 2;

    for (auto v : g[node])
    {
        if (col[v] == 1)
        { // Node - v is forming edge
            dfs(v, node);
        }
        else if (col[v] == 2)
        { // Node - v is back edge
            // We found a cycle !!
            if (is_cycle == 0)
            {
                int temp = node;
                while (temp != v)
                {
                    any_cycle.push_back(temp);
                    temp = parent[temp];
                }
                any_cycle.push_back(temp);
                reverse(any_cycle.begin(), any_cycle.end());
                any_cycle.push_back(temp); 
            }
            is_cycle = 1;
        }
        else if (col[v] == 3)
        { // Node - v is cross edge
          // Unimportant
        }
    }

    col[node] = 3;
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    col.assign(n + 1, 1);
    parent.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    for (int i = 1; i <= n; i++)
        if (col[i] == 1 && is_cycle == 0)
            dfs(i, 0);

    if (!is_cycle)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        cout << any_cycle.size() << endl;
        for (auto v : any_cycle)
            cout << v << " ";
    }

    cout << endl;
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