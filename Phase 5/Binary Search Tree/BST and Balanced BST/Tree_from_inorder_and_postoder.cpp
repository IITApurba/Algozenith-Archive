
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node *getBinaryTree(vector<int> &inorder, vector<int> &postorder)
{
    // Complete the function.
    if (inorder.empty() || postorder.empty())
        return NULL;
    int n = inorder.size();
    unordered_map<int, int> indexMap;
    for (int i = 0; i < n; i++)
        indexMap[inorder[i]] = i;
    int postIndex = n - 1;
    function<Node *(int, int)> buildTree = [&](int inStart, int inEnd) -> Node *
    {
        if (inStart > inEnd)
            return NULL;
        int rootVal = postorder[postIndex--];
        Node *root = new Node(rootVal);
        int inIndex = indexMap[rootVal];
        root->right = buildTree(inIndex + 1, inEnd);
        root->left = buildTree(inStart, inIndex - 1);
        return root;
    };
    return buildTree(0, n - 1);
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
        vector<int> arr1(n);
        for (int i = 0; i < n; i++)
            cin >> arr1[i];
        vector<int> arr2(n);
        for (int i = 0; i < n; i++)
            cin >> arr2[i];
        Node *tree = getBinaryTree(arr1, arr2);
        vector<int> ans;
        generateArray(tree, ans);
        for (auto v : ans)
            cout << v << " ";
        cout << "\n\n";
    }
    return 0;
}
