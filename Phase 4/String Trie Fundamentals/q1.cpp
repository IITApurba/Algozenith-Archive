#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

struct node
{
    int child[26];
    node()
    {
        memset(child, -1, sizeof(child));
    }
};

struct trie
{
    vector<node> nodes;

    trie()
    {
        node rootnode;
        // fill for root
        nodes.push_back(rootnode);
    }

    void insert(const string &s)
    {
        int curr_node_idx = 0;

        for (int i = 0; i < s.length(); i++)
        {
            int idx = s[i] - 'a';

            if (nodes[curr_node_idx].child[idx] == -1)
            {
                node new_node;

                nodes[curr_node_idx].child[idx] = nodes.size();

                nodes.push_back(new_node);
            }
            curr_node_idx = nodes[curr_node_idx].child[idx];
        }
    }

    int get_node_count()
    {
        return nodes.size();
    }
};

void solve()
{
    string s;
    cin >> s;
    trie t;
    for (int i = 0; i < s.size(); i++)
    {
        t.insert(s.substr(i));
    }

    // -1 BECAUSE ROOT IS NOT A SUBSTRING

    cout << t.get_node_count() - 1 << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}