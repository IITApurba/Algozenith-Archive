#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left, *right;

    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
private:
    Node *root;
    bool isBST = true;

public:
    BinaryTree() : root(nullptr) {}

    Node *buildTree(vector<int> &arr, int &index)
    {
        if (index >= arr.size() || arr[index] == -1)
            return nullptr;
        Node *node = new Node(arr[index]);
        index++;
        node->left = buildTree(arr, index);
        index++;
        node->right = buildTree(arr, index);
        return node;
    }

    void constructTree(vector<int> &arr)
    {
        int index = 0;
        root = buildTree(arr, index);
    }

    pair<int, int> isBSTUtil(Node *cur)
    {
        if (cur == nullptr)
            return {INT_MAX, INT_MIN};

        pair<int, int> left = isBSTUtil(cur->left);
        pair<int, int> right = isBSTUtil(cur->right);

        if (cur->val >= right.first)
            isBST = false;
        if (cur->val <= left.second)
            isBST = false;

        return {
            min(cur->val, left.first),
            max(cur->val, right.second)};
    }

    bool isBSTree()
    {
        isBST = true;
        isBSTUtil(root);
        return isBST;
    }
};

void solve()
{
    BinaryTree tree;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    tree.constructTree(arr);
    // Check if a BT is a BST
    cout << (tree.isBSTree() ? "yes" : "no") << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    cin >> t;
    
    while (t--)
        solve();

    return 0;
}
