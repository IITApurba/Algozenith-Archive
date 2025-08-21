#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

struct TrieNode
{
    int child[26];
    TrieNode()
    {
        memset(child, -1, sizeof(child));
    }
};

void solve()
{
    string S;
    cin >> S;
    int n = S.size();

    string goodMask;
    cin >> goodMask;

    int K;
    cin >> K;

    // 1) Build prefix-sum of bad characters
    vector<int> badPref(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        badPref[i + 1] = badPref[i] + (goodMask[S[i] - 'a'] == '0');
    }

    // 2) Initialize trie with root node
    vector<TrieNode> trie;
    trie.reserve(n * 10);
    trie.emplace_back(); // root at index 0

    int64_t distinctCount = 0;

    // 3) For each starting position, walk/inset into trie
    for (int i = 0; i < n; i++)
    {
        int node = 0;
        for (int j = i; j < n; j++)
        {
            // If adding S[j] would exceed K bad chars, stop
            if (badPref[j + 1] - badPref[i] > K)
                break;

            int c = S[j] - 'a';
            if (trie[node].child[c] == -1)
            {
                // create new node → new distinct substring
                trie[node].child[c] = trie.size();
                trie.emplace_back();
                distinctCount++;
            }
            node = trie[node].child[c];
        }
    }

    cout << distinctCount << "\n";
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
