#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;
const int N = 1e5 + 5;
string t = "0100";
int n;
int dp[N][5];

// count of binary strings such that it does not contain t as a subsequence using prefix match
int rec1(int level, int match)
{
    if (match == 4)
        return 0;
    if (level == n)
        return 1;
    if (dp[level][match] != -1)
        return dp[level][match];

    int ans = 0;
    ans += rec1(level + 1, match + 1);
    ans += rec1(level + 1, match);

    return dp[level][match] = ans;
}

// count of binary string that does not contain t as a subseq using Automata (FSM)
int rec2()
{
    int a = 1, b = 0, c = 0, d = 0;
    for (int i = 0; i < n; i++)
    {
        int newa = 0, newb = 0, newc = 0, newd = 0;
        newa = a;
        newb = a + b;
        newc = c + b;
        newd = d + c;
        a = newa, b = newb, c = newc, d = newd;
    }
    return a + b + c + d;
}

int dp3[100100][16];

int rec3(int level, int lastThree)
{
    if (level == n)
        return 1;

    if (dp3[level][lastThree] != -1)
        return dp3[level][lastThree];

    int ans = 0;
    // lastThree == 2 --> 010 put 1 only to, not match it with t
    // lastThree == 2 --> 10 || 010 || ... etc. ---> so we need (level>=3) strict transition only it is 2 and have 3 digits

    // 010 -> 010+0 is not good
    // 010 -> 010+1 is good
    if (level >= 3 && lastThree == 2)
        ans += rec3(level + 1, 5); // 101
    else
        ans = rec3(level + 1, ((lastThree << 1) | 0) & 7) + rec3(level + 1, ((lastThree << 1) | 1) & 7);

    return dp3[level][lastThree] = ans;
}

int dp4[100100][5];

int rec4(int level, int state)
{
    if (state == 4)
        return 0;
    if (level == n)
        return 1;
    if (dp4[level][state] != -1)
    {
        return dp4[level][state];
    }
    // strict transitions for every state in case of substrings matches
    int ans = 0;
    // state == 0 --> no match ""
    if (state == 0)
    {
        ans += rec4(level + 1, 0) + rec4(level + 1, 1);
    }
    else if (state == 1)
    {
        ans += rec4(level + 1, 1) + rec4(level + 1, 2);
    }
    else if (state == 2)
    {
        ans += rec4(level + 1, 0) + rec4(level + 1, 3);
    }
    else if (state == 3)
    {
        ans += rec4(level + 1, 2) + rec4(level + 1, 4);
    }

    
    return dp4[level][state] = ans;
}

void countStringsUsingPrefixMatch()
{
    memset(dp, -1, sizeof(dp));
    cout << rec1(0, 0) << endl;
}

void countStringsUsingAutomata()
{
    memset(dp, -1, sizeof(dp));
    cout << rec2() << endl;
}

void countStringsUsingBitmask()
{
    memset(dp3, -1, sizeof(dp3));
    cout << rec3(0, 0) << endl;
}

void countStringsUsingAutomata2()
{
    memset(dp4, -1, sizeof(dp4));
    cout << rec4(0, 0) << endl;
}

void solve()
{
    cin >> n;
    // subsq
    countStringsUsingPrefixMatch();
    countStringsUsingAutomata();
    // substring
    countStringsUsingBitmask();
    countStringsUsingAutomata2();
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;

    while (tt--)
    {
        solve();
    }
    return 0;
}