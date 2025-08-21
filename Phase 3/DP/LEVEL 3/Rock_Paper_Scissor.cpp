#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f(i, a, b) for (long long i = a; i <= b; i++)

int n, k;
string s;

/*
P: 0, R: 1, S: 2
*/
bool can_win(int i, int myMove)
{
    return (
        (s[i] == 'R' and myMove == 0) or
        (s[i] == 'P' and myMove == 2) or
        (s[i] == 'S' and myMove == 1));
}

int dp[1001][3][1001];
int rec(int i, int prev, int left)
{
    // pc
    if (i > n or left < 0)
        return -1e9;

    // bc
    if (i == n)
        return 0;

    // cc
    if (dp[i][prev][left] != -1)
        return dp[i][prev][left];

    // Xition
    int ans = 0;
    for (int mv = 0; mv <= 2; mv++)
    {
        ans = max(ans, can_win(i, mv) + rec(i + 1, mv, left - (prev != mv)));
    }

    // save and return
    return dp[i][prev][left] = ans;
}

string soln;
void generate(int i, int prev, int left)
{
    if (i == n)
        return;

    int ans = 0;
    for (int mv = 0; mv <= 2; mv++)
    {
        ans = max(ans, can_win(i, mv) + rec(i + 1, mv, left - (prev != mv)));
    }

    for (int mv = 0; mv <= 2; mv++)
    {
        if (ans == can_win(i, mv) + rec(i + 1, mv, left - (prev != mv)))
        {
            if (mv == 0)
                soln.pb('P');
            else if (mv == 1)
                soln.pb('R');
            else
                soln.pb('S');

            generate(i + 1, mv, left - (prev != mv));
            return;
        }
    }
}

void solve()
{
    cin >> n >> k >> s;

    memset(dp, -1, sizeof(dp));

    int ans = 0;

    ans = max({ans, rec(0, 0, k), rec(0, 1, k), rec(0, 2, k)});
    cout << ans << endl;

    soln = "";
    if (ans == can_win(0, 0) + rec(1, 0, k))
    {
        cout << 'P';
        generate(1, 0, k);
    }
    else if (ans == can_win(0, 1) + rec(1, 1, k))
    {
        cout << 'R';
        generate(1, 1, k);
    }
    else if (ans == can_win(0, 2) + rec(1, 2, k))
    {
        cout << 'S';
        generate(1, 2, k);
    }
    cout << soln << endl;
}

int main()
{
    int _t;
    cin >> _t;
    while (_t--)
        solve();
    return 0;
}