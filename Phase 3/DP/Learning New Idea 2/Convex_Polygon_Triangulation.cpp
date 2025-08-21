#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;
int dp[105][105]; // Max n = 100

int minScoreTriangulation(vector<int> &v, int n) {
    // Clear dp table
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            dp[i][j] = 0;

    // len = length of subpolygon
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            dp[i][j] = INF;
            for (int k = i + 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + v[i] * v[j] * v[k]);
            }
        }
    }
    return dp[0][n - 1];
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &x : v) cin >> x;
    cout << minScoreTriangulation(v, n) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
