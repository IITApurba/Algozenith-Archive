#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
const int INF = 1e9;

int N, M, K;
vector<string> board;
int dp[105][105][15];

int rec(int i, int j, int mod)
{
    // Purning
    if (j < 0 || j >= M)
        return -INF;

    // Base Case
    if (i == 0)
    {
        int val = board[i][j] - '0';
        return (val % K == mod) ? val : -INF;
    }

    // Cache Check
    if (dp[i][j][mod] != -1)
        return dp[i][j][mod];

    // Computation
    int val = board[i][j] - '0';
    int new_mod = (mod - val % K + K) % K;

    int left = rec(i - 1, j - 1, new_mod);
    int right = rec(i - 1, j + 1, new_mod);

    int best_prev = max(left, right);
    if (best_prev < 0)
        return dp[i][j][mod] = -INF;

    // Save and return
    return dp[i][j][mod] = val + best_prev;
}

void solve()
{
    cin >> N >> M >> K;
    board.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> board[i];

    memset(dp, -1, sizeof(dp));

    int ans = -1;

    for (int j = 0; j < M; ++j)
        ans = max(ans, rec(N - 1, j, 0));

    cout << (ans < 0 ? -1 : ans) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
