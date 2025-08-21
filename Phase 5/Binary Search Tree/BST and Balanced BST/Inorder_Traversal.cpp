#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> vis;

void Trav(Node *node)
{
    if (node == NULL)
        return;
    Trav(node->left);
    vis.push_back(node->val);
    Trav(node->right);
}

vector<int> getInorderTraversal(Node *root)
{
    // Complete the function
    vis.clear();
    Trav(root);
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
