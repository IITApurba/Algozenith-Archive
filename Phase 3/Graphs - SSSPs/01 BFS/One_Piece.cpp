#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m;
vector<vector<int>> grid;
vector<vector<int>> dis;

bool is_valid(int nx, int ny)
{
    if (nx >= 0 && ny >= 0 && nx < n && ny < m)
        return 1;
    else
        return 0;
}

void bfs(int i, int j)
{
    deque<pair<int, int>> dq;

    dis[i][i] = 0;
    dq.push_front({i, i});

    while (!dq.empty())
    {
        auto [x, y] = dq.front();
        dq.pop_front();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (is_valid(nx, ny))
            {
                int cost = (grid[x][y] == dir + 1) ? 0 : 1;

                if (dis[nx][ny] > dis[x][y] + cost)
                {
                    dis[nx][ny] = dis[x][y] + cost;

                    if (cost == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    grid.resize(n, vector<int>(m));
    dis.resize(n, vector<int>(m, 1e9));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    bfs(0, 0);

    cout << dis[n - 1][m - 1] << "\n";
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
