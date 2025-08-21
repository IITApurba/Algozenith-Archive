#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

string s;
int k;
vector<string> ans;

struct node
{
    node *ch[26] = {NULL};
    bool isEnd = false;
    string word = "";
};

void SearchMatch(node *cur, int pos, int misMatch)
{
    if (misMatch > k)
        return;

    if (pos == s.size())
    {
        if (cur->isEnd)
            ans.push_back(cur->word);
        return;
    }

    for (int i = 0; i < 26; i++)
    {
        if (cur->ch[i] != NULL)
        {
            int newMismatch = misMatch + ((i + 'a') != s[pos]);
            SearchMatch(cur->ch[i], pos + 1, newMismatch);
        }
    }
}

void solve()
{
    int n;
    cin >> n >> s >> k;

    node *root = new node();
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        node *cur = root;
        for (char c : temp)
        {
            int idx = c - 'a';
            if (cur->ch[idx] == NULL)
                cur->ch[idx] = new node();
            cur = cur->ch[idx];
        }
        cur->isEnd = true;
        cur->word = temp;
    }

    SearchMatch(root, 0, 0);

    for (auto &x : ans)
        cout << x << endl;
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
