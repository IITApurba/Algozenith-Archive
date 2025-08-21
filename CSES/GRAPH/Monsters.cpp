#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second

using state = pair<int, int>;

int n, m;
vector<vector<char>> arr;
state st;
vector<state> mons;
vector<state> bd_cells;
vector<vector<int>> dis_pers, dis_mons;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool is_valid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] == '.');
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
            if (is_valid(nx, ny) && dis_mons[nx][ny] > dis_mons[x][y] + 1)
            {
                dis_mons[nx][ny] = dis_mons[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

void bfs_with_path()
{
    queue<state> q;
    vector<vector<state>> parent(n, vector<state>(m, {-1, -1}));
    vector<vector<char>> move(n, vector<char>(m));
    dis_pers[st.F][st.S] = 0;
    q.push(st);

    while (!q.empty())
    {
        int x = q.front().F, y = q.front().S;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k], ny = y + dy[k];
            if (is_valid(nx, ny) && dis_pers[nx][ny] > dis_pers[x][y] + 1)
            {
                dis_pers[nx][ny] = dis_pers[x][y] + 1;
                parent[nx][ny] = {x, y};

                if (dx[k] == 1) move[nx][ny] = 'D';
                else if (dx[k] == -1) move[nx][ny] = 'U';
                else if (dy[k] == 1) move[nx][ny] = 'R';
                else move[nx][ny] = 'L';

                q.push({nx, ny});
            }
        }
    }

    // Try to reach a safe boundary cell
    for (auto cell : bd_cells)
    {
        int x = cell.F, y = cell.S;
        if (dis_pers[x][y] < dis_mons[x][y])
        {
            cout << "YES\n";
            cout << dis_pers[x][y] << '\n';

            string path = "";
            while (make_pair(x, y) != st)
            {
                path += move[x][y];
                auto p = parent[x][y];
                x = p.F;
                y = p.S;
            }
            reverse(path.begin(), path.end());
            cout << path << '\n';
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
    dis_pers.assign(n, vector<int>(m, 1e9));
    dis_mons.assign(n, vector<int>(m, 1e9));

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
                    bd_cells.push_back({i, j});
            }
            else if (ch == 'M')
            {
                mons.push_back({i, j});
            }
            else if (ch == '.' && (i == 0 || j == 0 || i == n - 1 || j == m - 1))
            {
                bd_cells.push_back({i, j});
            }
        }
    }

    multi_bfs();
    bfs_with_path();

    return 0;
}
