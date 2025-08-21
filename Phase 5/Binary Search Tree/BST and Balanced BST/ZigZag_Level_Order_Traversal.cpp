
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> vis;

void dfs(Node *node, int level)
{
    if (node == nullptr)
        return;

    if (vis.size() == level)
        vis.push_back(vector<int>());

    // Check if this level is even or odd
    if (level % 2 == 0)
        vis[level].push_back(node->val); // Left to Right
    else
        vis[level].insert(vis[level].begin(), node->val); // Right to Left

    dfs(node->left, level + 1);
    dfs(node->right, level + 1);
}

vector<vector<int>> getZigzagLevelorderTraversal(Node *root)
{
    vis.clear();
    dfs(root, 0);
    return vis;
}

Node *getBinaryTree(vector<int> &num, int *ind)
{
    if (num[*ind] == -1)
        return NULL;
    Node *node = new Node(num[*ind]);
    (*ind)++;
    node->left = getBinaryTree(num, ind);
    (*ind)++;
    node->right = getBinaryTree(num, ind);
    return node;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        assert(n <= 1000000);
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int ind = 0;
        Node *tree = getBinaryTree(arr, &ind);
        vector<vector<int>> ans = getZigzagLevelorderTraversal(tree);
        for (auto u : ans)
        {
            for (auto v : u)
            {
                cout << v << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}
