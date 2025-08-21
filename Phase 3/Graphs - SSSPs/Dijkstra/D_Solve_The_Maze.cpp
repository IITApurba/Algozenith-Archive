#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i)
        cin >> grid[i];

    // Step 1: Block adjacent cells of bad people
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 'B')
            {
                for (int d = 0; d < 4; ++d)
                {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m)
                    {
                        if (grid[ni][nj] == '.')
                            grid[ni][nj] = '#'; // Block empty neighbor
                    }
                }
            }
        }
    }

    // Step 2: BFS from the exit cell if it's not blocked
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    if (grid[n - 1][m - 1] != '#')
    {
        q.push({n - 1, m - 1});
        vis[n - 1][m - 1] = true;
    }

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d)
        {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (!vis[nx][ny] && grid[nx][ny] != '#')
                {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    // Step 3: Check all 'G' must be reachable, and all 'B' must NOT
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 'G' && !vis[i][j])
            {
                cout << "No\n";
                return;
            }
            if (grid[i][j] == 'B' && vis[i][j])
            {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}