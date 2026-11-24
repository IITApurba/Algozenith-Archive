#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
int mid[10][10];     // mid[a][b] = cell between a and b (0 if none)
int dp[10][1 << 10]; // dp[last][mask]

// is this cell already used?
bool isUsed(int mask, int cell)
{
    return (mask >> cell) & 1;
}

// last = current cell, mask = used cells, cnt = number of used cells
int rec(int last, int mask, int cnt)
{
    // base case
    if (cnt == n)
        return 1;

    // cache check
    if (dp[last][mask] != -1)
        return dp[last][mask];

    // transition
    int ans = 0;

    for (int next = 1; next <= 9; next++)
    {
        if (isUsed(mask, next)) // rule 1: cell not used yet
            continue;

        int between = mid[last][next];
        if (between != 0 && !isUsed(mask, between)) // rule 2: no jump over an unused cell
            continue;

        ans += rec(next, mask | (1 << next), cnt + 1);
    }

    // save and return
    return dp[last][mask] = ans;
}

void solve()
{
    cin >> n;

    // 1 2 3
    // 4 5 6
    // 7 8 9
    // 3 rows 3 columns 2 digonals
    mid[1][3] = mid[3][1] = 2; // rows
    mid[4][6] = mid[6][4] = 5;
    mid[7][9] = mid[9][7] = 8;
    mid[1][7] = mid[7][1] = 4; // columns
    mid[2][8] = mid[8][2] = 5;
    mid[3][9] = mid[9][3] = 6;
    mid[1][9] = mid[9][1] = 5; // diagonals
    mid[3][7] = mid[7][3] = 5;

    memset(dp, -1, sizeof(dp));

    int ans = 0;
    for (int start = 1; start <= 9; start++)
        ans += rec(start, 1 << start, 1);

    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}