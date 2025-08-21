
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *left, *right;

    Node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};



vector<int> getInorderTraversal(Node *root)
{
    vector<int> result;
    function<void(Node *)> inorder = [&](Node *node)
    {
        if (!node)
            return;
        inorder(node->left);         // Step 1: Left Subtree
        result.push_back(node->val); // Step 2: Root
        inorder(node->right);        // Step 3: Right Subtree
    };
    inorder(root);
    return result;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int ind = 0;
        Node *tree = getBinaryTree(arr, &ind);
        vector<int> ans = getInorderTraversal(tree);
        for (auto v : ans)
        {
            cout << v << " ";
        }
        cout << "\n";
    }
    return 0;
}
