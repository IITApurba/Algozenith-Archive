#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    // Use Map when -> Lexo Traverse is required or Character Flexibility
    // Use Array when -> Fixed Character Set (like lowercase letters) and Speed is a priority
    // Array logic would be:
    // TrieNode *children[26] = {nullptr}; // For lowercase letters a-z

    map<char, TrieNode *> children;
    bool isEnd = false;
};

class Trie
{
private:
    TrieNode *root;

    void dfs(TrieNode *node, string &currentSuffix, vector<string> &results, int K)
    {
        if (results.size() >= K)
            return;
        if (node->isEnd)
        {
            results.push_back(currentSuffix);
        }
        for (auto &pair : node->children)
        {
            currentSuffix.push_back(pair.first);
            dfs(pair.second, currentSuffix, results, K);
            currentSuffix.pop_back();
            if (results.size() >= K)
                return;
        }
    }

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *current = root;
        for (char c : word)
        {
            if (current->children.find(c) == current->children.end())
            {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEnd = true;
    }

    vector<string> getTopKStrings(string prefix, int K)
    {
        vector<string> results;
        TrieNode *current = root;
        for (char c : prefix)
        {
            if (current->children.find(c) == current->children.end())
            {
                return results; // Prefix not found
            }
            current = current->children[c];
        }

        string suffix;
        dfs(current, suffix, results, K);

        // Prepend the prefix to each suffix to form the full strings
        for (string &s : results)
        {
            s = prefix + s;
        }

        // Ensure only top K elements are returned (in case K < results.size())
        if (results.size() > K)
        {
            results.resize(K);
        }
        return results;
    }
};

int main()
{
    Trie trie;
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        string word;
        cin >> word;
        trie.insert(word);
    }
    string prefix;
    cin >> prefix;

    vector<string> topKStrings = trie.getTopKStrings(prefix, K);

    for (const string &s : topKStrings)
    {
        cout << s << endl;
    }

    return 0;
}
