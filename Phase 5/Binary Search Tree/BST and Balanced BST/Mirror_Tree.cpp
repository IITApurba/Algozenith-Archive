
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node *getMirrorTree(Node *root)
{
    // Complete the function
    if (root == NULL)
        return NULL;

    swap(root->left, root->right);

    getMirrorTree(root->left);
    getMirrorTree(root->right);

    return root;
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

void generateArray(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        ans.push_back(-1);
        return;
    }
    ans.push_back(root->val);
    generateArray(root->left, ans);
    generateArray(root->right, ans);
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
        tree = getMirrorTree(tree);
        vector<int> ans;
        generateArray(tree, ans);
        for (auto v : ans)
            cout << v << " ";
        cout << "\n";
    }
    return 0;
}
