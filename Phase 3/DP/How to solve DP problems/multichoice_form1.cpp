#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n;
int w[3003], v[3003];
int W;
int dp[3003][3003];
// O(N*W)
int rec(int level, int w_left)
{
    // pruning
    // basecase
    if (level == n)
        return 0;
    // cache check
    if (dp[level][w_left] != -1)
        return dp[level][w_left];
    // transition
    int ans = rec(level + 1, w_left);
    if (w[level] <= w_left)
        ans = max(ans, rec(level, w_left - w[level]) + v[level]);

    // save and return
    return dp[level][w_left] = ans;
}

vector<int> solution;
void generate(int level, int w_left)
{
    if (level == n)
        return; // Base case

    int dont_take = rec(level + 1, w_left);

    if (w[level] <= w_left)
    {
        int take = rec(level + 1, w_left - w[level]) + v[level];

        if (take >= dont_take)
        { // Agar lena better hai
            solution.push_back(level);
            generate(level + 1, w_left - w[level]);
            return; // Iske baad koi kaam nahi, toh return kar do
        }
    }

    // Agar lena possible nahi ya lena faydemand nahi hai, toh skip karna hai
    generate(level + 1, w_left);
}

void solve()
{
    cin >> n;
    cin >> W;

    for (int i = 0; i < n; i++)
        cin >> w[i];

    for (int i = 0; i < n; i++)
        cin >> v[i];

    memset(dp, -1, sizeof(dp));

    cout << rec(0, W) << endl;
    generate(0, W);

    cout << solution.size() << endl;

    for (auto v : solution)
        cout << v << " ";

    cout << endl;
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