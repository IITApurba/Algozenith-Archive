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
    bool is_BBST = true;

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

    int isBBSTUtil(Node *cur)
    {
        if (cur == nullptr)
            return 0;

        int leftHeight = isBBSTUtil(cur->left);
        int rightHeight = isBBSTUtil(cur->right);

        if (abs(leftHeight - rightHeight) > 1)
            is_BBST = false;

        return max(leftHeight, rightHeight) + 1;
    }

    bool isBBSTree()
    {
        is_BBST = true;
        isBBSTUtil(root);
        return is_BBST;
    }
};

void solve()
{
    BinaryTree tree;
    vector<int> arr = {4, 2, 5, 1, 3};
    tree.constructTree(arr);

    // Check if a BT is a BBST
    cout << "Is the binary tree a BBST? ";
    cout << (tree.isBBSTree() ? "Yes" : "No") << endl;
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
