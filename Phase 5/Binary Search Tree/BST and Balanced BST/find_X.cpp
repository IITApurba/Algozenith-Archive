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

    bool findX(Node *node, int x, vector<int> &path)
    {
        if (!node)
            return false;

        path.push_back(node->val);

        if (node->val == x)
            return true;

        if (findX(node->left, x, path) || findX(node->right, x, path))
            return true;

        path.pop_back(); // backtrack
        return false;
    }

    vector<int> getPathToX(int x)
    {
        vector<int> path;
        findX(root, x, path);
        return path;
    }
};

void solve()
{
    BinaryTree tree;
    vector<int> arr = {5, 3, 1, -1, -1, 4, -1, -1, 8, 7, -1, -1, 9, -1, -1}; // preorder with -1 as NULL
    tree.constructTree(arr);

    int x = 4;

    vector<int> path = tree.getPathToX(x);

    if (!path.empty() && path.back() == x)
    {
        cout << "Path to " << x << ": ";
        for (int val : path)
            cout << val << " ";
        cout << "\n";
    }
    else
    {
        cout << "Value " << x << " not found in the tree.\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    
    while (t--)
        solve();

    return 0;
}
