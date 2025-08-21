#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n, m, rooms;
vector<vector<int>> g;
vector<vector<bool>> vis;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isValid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if (vis[x][y])
        return false;
    else
        return true;
}

void dfs(int i, int j)
{

    vis[i][j] = 1;

    for (int k = 0; k < 4; k++)
    {
        if (isValid(i + dx[k], j + dy[k]))
            dfs(i + dx[k], j + dy[k]);
    }
}

void CC()
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
                vis[i][j] = 1;
        }
    }

    CC();

    cout << rooms << endl;
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