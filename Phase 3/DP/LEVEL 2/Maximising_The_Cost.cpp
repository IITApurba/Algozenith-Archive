#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, k;
string A;
int done[101][101][27];
int dp[101][101][27];
int cost[28][28];

int rec(int l, int k, int pre)
{

    if (k < 0)
        return -1e9;
    if (l == n)
        return 0;

    if (done[l][k][pre] != -1)
        return dp[l][k][pre];

    int curr = (A[l] - 'a');

    int ans = -1e9;

    int cst = (pre < 26 ? cost[pre][curr] : 0);
    ans = max(ans, cst + rec(l + 1, k, curr));

    for (int i = 0; i < 26; i++)
    {
        if (i == curr)
            continue;
        int cst = (pre < 26 ? cost[pre][i] : 0);
        if (ans < cst + rec(l + 1, k - 1, i))
        {
            ans = cst + rec(l + 1, k - 1, i);
            // cout<<"*";
        }
    }
    done[l][k][pre] = 1;
    return dp[l][k][pre] = ans;
}

void solve()
{
    cin >> A >> k;
    n = A.size();
    cin >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= k; j++)
            for (int l = 0; l < 27; l++)
            {
                dp[i][j][l] = 0;
                done[i][j][l] = -1;
            }
    memset(cost, 0, sizeof(cost));

    while (m--)
    {
        char x, y;
        int c;
        cin >> x >> y >> c;
        cost[x - 'a'][y - 'a'] = c;
    }
    // for(int i=0;i<26;i++)
    // {for(int j=0;j<26;j++)
    // {cout<<cost[i][j]<<" ";}cout<<"\n";}

    cout << rec(0, k, 26) << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve(

        );
    }
}