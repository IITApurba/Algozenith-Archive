#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9
#define F first
#define S second
#define ld long double
#define endl '\n'
const int mod = 1e9 + 7;
// using ll= long long;
int dp[41][41][41];
int done[41][41][41];

string s1, s2;

bool rec(int l, int r, int i)
{
    int j = i + (r - l);
    if (l > r || i > j)
        return false;

    if (l == r)
        return (s1[l] == s2[i]);

    if (done[l][r][i])
        return dp[l][r][i];

    done[l][r][i] = 1;

    bool ans = false;

    if (s1.substr(l, r - 1 + 1) == s2.substr(i, j - i + 1))
    {
        return dp[l][r][i] = true;
    }

    for (int k = l; k < r; k++)
    {
        int lenLeft = k - l + 1;

        if (rec(l, k, i) && rec(k + 1, r, i + lenLeft))
        {
            ans = true;
            break;
        }
        if (rec(l, k, j - lenLeft + 1) && rec(k + 1, r, i))
        {
            ans = true;
            break;
        }
    }

    return dp[l][r][i] = ans;
}

void solve()
{
    cin >> s1 >> s2;
    int n = s1.size();

    memset(dp, 0, sizeof(dp));
    memset(done, 0, sizeof(done));

    if (rec(0, n - 1, 0))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int _t = 1;
    cin >> _t;
    while (_t--)
    {
        solve();
    }
    return 0;
}