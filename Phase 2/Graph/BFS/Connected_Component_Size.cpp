#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> state;
#define F first
#define S second

int n, m;
vector<vector<int>> arr;
vector<vector<int>> vis;
unordered_map<int, int> component_size; // Stores size of each component

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// Function to get valid neighbours (only connected 0s)
vector<state> neighbours(state node)
{
    vector<state> ans;
    for (int i = 0; i < 4; i++)
    {
        int x = node.F + dx[i];
        int y = node.S + dy[i];

        if (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] == 0 && !vis[x][y])
            ans.push_back({x, y});
    }
    return ans;
}

// BFS to find all connected 0s and calculate component size
void bfs(state node, int room_no)
{
    queue<state> q;
    q.push(node);
    vis[node.F][node.S] = room_no;

    int size = 1; // Start size count

    while (!q.empty())
    {
        state cur = q.front();
        q.pop();

        for (state v : neighbours(cur))
        {
            if (!vis[v.F][v.S])
            {
                vis[v.F][v.S] = room_no;
                q.push(v);
                size++; // Increase room size
            }
        }
    }

    // Store component size
    component_size[room_no] = size;
}

void solve()
{
    cin >> n >> m;
    arr.assign(n, vector<int>(m));
    vis.assign(n, vector<int>(m, 0));
    component_size.clear();

    // Read input
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    int room_no = 0;

    // Find all components
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && arr[i][j] == 0)
            {
                room_no++;
                bfs({i, j}, room_no);
            }
        }
    }

    // Replace 0s with their component size
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                int size = component_size[vis[i][j]];
                if (size > 1)
                    arr[i][j] = size; // Replace with size
            }
        }
    }

    // Print final matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
