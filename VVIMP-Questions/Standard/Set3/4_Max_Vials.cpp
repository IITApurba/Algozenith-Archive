#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;
vector<int> x, y;
int dp[1010][1010];

int rec(int idx, int rem)
{
    // Base case
    if (idx == n) return 0;

    // Pruning
    if (rem == 0) return 0;

    // Cache check
    if (dp[idx][rem] != -1)
        return dp[idx][rem];

    // Transition
    int take = 0;

    for (int i = 1; i <= min(x[idx], rem); i++)
    {
        take = max(take, i * y[idx] + rec(idx + 1, rem - i));
    }

    int not_take = rec(idx + 1, rem);

    // Save and return
    return dp[idx][rem] = max(take, not_take);
}

void solve()
{
    cin >> n >> m;

    x.resize(n);
    y.resize(n);

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    cout << rec(0, m) << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}