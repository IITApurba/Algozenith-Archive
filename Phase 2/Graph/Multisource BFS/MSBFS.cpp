#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second

using state = pair<int, int>;

int n, m;
vector<vector<char>> arr;
state st;
vector<state> mons;           // store monster cells
vector<vector<int>> dis_pers; // store min distances from person
vector<vector<int>> dis_mons; // store min distances from monsters
vector<state> bd_cells;       // store boundary cells

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool is_valid(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] == '.')
    {
        return true;
    }
    return false;
}

void multi_bfs()
{
    queue<state> q;
    for (auto it : mons)
    {
        q.push(it);
        dis_mons[it.F][it.S] = 0;
    }

    while (!q.empty())
    {
        int x = q.front().F, y = q.front().S;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k], ny = y + dy[k];
            if (is_valid(nx, ny))
            {
                if (dis_mons[nx][ny] > dis_mons[x][y] + 1)
                {
                    q.push({nx, ny});
                    dis_mons[nx][ny] = dis_mons[x][y] + 1;
                }
            }
        }
    }
}

void bfs(state node)
{
    queue<state> q;
    q.push(node);
    dis_pers[node.F][node.S] = 0;

    while (!q.empty())
    {
        int x = q.front().F, y = q.front().S;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k], ny = y + dy[k];
            if (is_valid(nx, ny))
            {
                if (dis_pers[nx][ny] > dis_pers[x][y] + 1)
                {
                    q.push({nx, ny});
                    dis_pers[nx][ny] = dis_pers[x][y] + 1;
                }
            }
        }
    }
}

void solve()
{
    // Multisource BFS to compute minimum distance of any monster to boundary
    multi_bfs();

    // Plain BFS to compute minimum distance of any boundary cell to person
    bfs(st);

    // Check if distance of boundary cell from person is less than or equal to minimum distance of any monster to boundary
    for (auto cell : bd_cells)
    {
        if (dis_pers[cell.F][cell.S] < dis_mons[cell.F][cell.S])
        {
            cout << "YES\n";
            cout << dis_pers[cell.F][cell.S] << '\n';
            return;
        }
    }
    cout << "NO\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            arr[i][j] = ch;
            if (ch == 'A')
            {
                st = {i, j};
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    bd_cells.push_back({i, j});
                }
            }
            else if (ch == 'M')
            {
                mons.push_back({i, j});
            }
            else if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && ch == '.')
            {
                bd_cells.push_back({i, j});
            }
        }
    }
    dis_pers.assign(n, vector<int>(m, 1e9));
    dis_mons.assign(n, vector<int>(m, 1e9));

    solve();
    return 0;
}
