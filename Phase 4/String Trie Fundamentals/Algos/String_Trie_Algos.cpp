#include <bits/stdc++.h>
using namespace std;

// We can store any data structure(s) as per our need to a problem
class TrieNode
{
public:
    map<char, TrieNode *> children;
    bool isEndOfWord;
    int prefix;
    vector<string> wend; // store all the strings which end at that node
    TrieNode()
    {
        isEndOfWord = false;
        prefix = 0;
    }
};

class Trie
{
public:
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
            node->prefix++;
            if (node->children.find(ch) == node->children.end())
            {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
        node->wend.push_back(word);
    }

    bool search(string word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (node->children.find(ch) == node->children.end())
            {
                return false;
            }
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (char ch : prefix)
        {
            if (node->children.find(ch) == node->children.end())
            {
                return false;
            }
            node = node->children[ch];
        }
        return true;
    }

    void deletion(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            node->prefix--;
            if (node->children.find(c) == node->children.end())
            {
                return;
            }
            node = node->children[c];
        }
        node->isEndOfWord = false;
        auto it = find(node->wend.begin(), node->wend.end(), word);
        if (it != node->wend.end())
            node->wend.erase(it);
    }
};

void solve()
{
    Trie trie;

    trie.insert("aaaaabbb");
    trie.insert("aaa");

    trie.search("aaa") ? cout << "Found aaa\n" : cout << "Not Found aaa\n";

    trie.deletion("a");
    trie.search("aaa") ? cout << "Found aaa\n" : cout << "Not Found a\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

    while (t--)
        solve();

    return 0;
}