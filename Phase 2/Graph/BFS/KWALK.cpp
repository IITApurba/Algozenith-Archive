#include <bits/stdc++.h>
using namespace std;

int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)
{
    Sx--, Sy--, Fx--, Fy--;

    int ans = -1;

    pair<int, int> mv[] = {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};

    int vis[N][N]; 
    memset(vis, -1, sizeof(vis));

    queue<pair<int, int>> q;

    q.push({Sx, Sy});
    vis[Sx][Sy] = 0;

    while (q.size())
    {
        auto a = q.front();
        q.pop();

        int x = a.first, y = a.second, curr = vis[x][y];

        if (x == Fx && y == Fy)
        {
            ans = curr;
            break;
        }

        for (auto i : mv)
        {
            int x1 = x + i.first, y1 = y + i.second;

            if (x1 < 0 || y1 < 0 || x1 >= N || y1 >= N || vis[x1][y1] != -1)
                continue;

            vis[x1][y1] = curr + 1;
            q.push({x1, y1});
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;

    while (test_case--)
    {
        int N, Sx, Sy, Fx, Fy;
        cin >> N >> Sx >> Sy >> Fx >> Fy;

        cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
    }
}
