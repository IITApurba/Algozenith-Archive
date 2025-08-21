#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, rooms; // rooms = number of Connected Components
vector<vector<bool>> vis;
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if (vis[x][y])
        return false;
    return true;
}

void dfs(int i, int j)
{
    vis[i][j] = true;

    for (auto p : moves)
    {
        if (isValid(i + p.first, j + p.second))
        {
            dfs(i + p.first, j + p.second);
        }
    }
}

void connected_components()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                dfs(i, j);
                rooms++;
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    vis.resize(n);

    for (int i = 0; i < n; i++)
    {
        vis[i].resize(m);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;

            if (c == '#')
                vis[i][j] = true;
        }
    }

    connected_components();

    cout << rooms << endl;
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