#include <bits/stdc++.h>
using namespace std;

#define int long long

struct TrieNode
{
    map<char, TrieNode *> children;
    bool isEnd = false;
    vector<string> words; // Words ending at this node (optional, helpful in lex sorting)
};

class Trie
{
private:
    TrieNode *root;

    void dfs(TrieNode *node, string &current, vector<string> &res, int K)
    {
        if ((int)res.size() >= K)
            return;
        if (node->isEnd)
            res.push_back(current);
        for (auto &p : node->children)
        {
            current.push_back(p.first);
            dfs(p.second, current, res, K);
            current.pop_back();
        }
    }

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(const string &word)
    {
        TrieNode *cur = root;
        for (char ch : word)
        {
            if (!cur->children.count(ch))
                cur->children[ch] = new TrieNode();
            cur = cur->children[ch];
        }
        cur->isEnd = true;
    }

    vector<string> getSuggestions(const string &prefix, int K)
    {
        TrieNode *cur = root;
        for (char ch : prefix)
        {
            if (!cur->children.count(ch))
                return {};
            cur = cur->children[ch];
        }
        vector<string> result;
        string temp = prefix;
        dfs(cur, temp, result, K);
        return result;
    }
};

void solve()
{
    int N, MaxLen, Q;
    cin >> N >> MaxLen >> Q;
    Trie trie;
    for (int i = 0; i < N; ++i)
    {
        int len;
        string word;
        cin >> len >> word;
        trie.insert(word);
    }

    while (Q--)
    {
        int len, K;
        string query;
        cin >> len >> query >> K;
        string prefix = "";
        for (char ch : query)
        {
            prefix += ch;
            vector<string> suggestions = trie.getSuggestions(prefix, K);
            if (suggestions.empty())
            {
                cout << '\n';
            }
            else
            {
                for (string &word : suggestions)
                    cout << word << " ";
                cout << '\n';
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
=

    while (t--)
        solve();

    return 0;
}
