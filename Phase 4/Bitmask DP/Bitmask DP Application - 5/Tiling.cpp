#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n, m, S;
vector<vector<int>> transitions;
vector<vector<int>> memo;
vector<vector<bool>> seen;

// Build transitions: for each mask cur, all masks nxt that complete a column
void buildTransitions()
{
    function<void(int, int, int)> dfs = [&](int pos, int cur, int nxt)
    {
        if (pos == n)
        {
            transitions[cur].push_back(nxt);
            return;
        }
        if (cur & (1 << pos))
        {
            dfs(pos + 1, cur, nxt);
        }
        else
        {
            // vertical domino
            if (pos + 1 < n && !(cur & (1 << (pos + 1))))
            {
                dfs(pos + 2, cur, nxt);
            }
            // horizontal domino
            dfs(pos + 1, cur, nxt | (1 << pos));
        }
    };

    for (int mask = 0; mask < S; mask++)
    {
        dfs(0, mask, 0);
    }
}

// Recursive DP: count ways from column `col` with current-column mask `mask`
int countWays(int col, int mask)
{
    if (col == m)
    {
        // If we've processed all columns, must have no overhang
        return mask == 0;
    }
    if (seen[col][mask])
    {
        return memo[col][mask];
    }
    seen[col][mask] = true;
    int &res = memo[col][mask];
    res = 0;
    for (int nxt : transitions[mask])
    {
        res += countWays(col + 1, nxt);
    }
    return res;
}

void solve()
{
    cin >> n >> m;
    if (n > m)
        swap(n, m);
    S = 1 << n;
    transitions.assign(S, {});
    buildTransitions();

    // memo[col][mask]: -1 = uncomputed
    memo.assign(m + 1, vector<int>(S, 0));
    seen.assign(m + 1, vector<bool>(S, false));

    cout << countWays(0, 0) << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
