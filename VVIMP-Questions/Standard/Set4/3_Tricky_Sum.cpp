#include <bits/stdc++.h>
using namespace std;

int jump_to[101];   // jump_to[i] = where you end up after landing on cell i
int dist[101];      // dist[i] = min rolls to reach cell i (-1 = not reached)

void solve()
{
    // no snake/ladder by default: you stay where you land
    for (int i = 1; i <= 100; i++)
        jump_to[i] = i;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int st, en;
        cin >> st >> en;
        jump_to[st] = en;       // ladder
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int st, en;
        cin >> st >> en;
        jump_to[st] = en;       // snake
    }

    // BFS from cell 1
    for (int i = 1; i <= 100; i++)
        dist[i] = -1;

    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        // try every dice roll
        for (int dice = 1; dice <= 6; dice++)
        {
            int nxt = cur + dice;
            if (nxt > 100)
                break;                  // overshoot, so no move

            nxt = jump_to[nxt];         // forced snake/ladder, same roll

            if (dist[nxt] == -1)        // first visit = fewest rolls
            {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }

    cout << dist[100] << "\n";          // -1 if 100 can't be reached
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}