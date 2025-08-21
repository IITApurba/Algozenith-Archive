#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

class TrieNode
{
public:
    map<char, TrieNode *> children;
    bool isEndOfWord;
    string word;
    TrieNode()
    {
        isEndOfWord = false;
        word = "";
    }
};

class Trie
{
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (node->children.find(ch) == node->children.end())
            {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
        node->word = word;
    }

    TrieNode *getPrefixNode(string prefix)
    {
        TrieNode *node = root;

        for (char ch : prefix)
        {
            if (node->children.find(ch) == node->children.end())
            {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

    void dfs(TrieNode *node, int &k, vector<string> &result)
    {
        if (!node || k == 0)
            return;
        if (node->isEndOfWord)
        {
            result.push_back(node->word);
            k--;
            if (k == 0)
                return;
        }
        for (auto &[ch, child] : node->children)
        {
            dfs(child, k, result);
            if (k == 0)
                return;
        }
    }

    vector<string> query(string prefix, int k)
    {
        TrieNode *node = getPrefixNode(prefix);
        vector<string> result;
        dfs(node, k, result);
        return result;
    }
};

void solve()
{
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