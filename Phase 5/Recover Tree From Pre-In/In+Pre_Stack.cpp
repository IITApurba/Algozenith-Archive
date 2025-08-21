#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n;
vector<char> InOrder, PreOrder;

struct TreeNode
{
    char data;
    TreeNode *left, *right;

    TreeNode(char val)
    {
        data = val;
        left = right = NULL;
    }
};

TreeNode *buildTree()
{
    if (n == 0)
        return NULL;

    stack<TreeNode *> st;
    TreeNode *root = new TreeNode(PreOrder[0]);
    st.push(root);

    int inIndex = 0;
    for (int preIndex = 1; preIndex < n; preIndex++)
    {
        TreeNode *node = st.top();
        TreeNode *child = new TreeNode(PreOrder[preIndex]);

        if (node->data != InOrder[inIndex])
        {
            node->left = child;
            st.push(child);
        }
        else
        {
            while (!st.empty() && st.top()->data == InOrder[inIndex])
            {
                node = st.top();
                st.pop();
                inIndex++;
            }
            node->right = child;
            st.push(child);
        }
    }

    return root;
}

void printPostorder(TreeNode *root)
{
    if (!root)
        return;

    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

void solve()
{
    cin >> n;

    InOrder.resize(n);
    PreOrder.resize(n);

    for (int i = 0; i < n; i++)
        cin >> InOrder[i];

    for (int i = 0; i < n; i++)
        cin >> PreOrder[i];

    TreeNode *root = buildTree();

    printPostorder(root);
    cout << "\n";
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
