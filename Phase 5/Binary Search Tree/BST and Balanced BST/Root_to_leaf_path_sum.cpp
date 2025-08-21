
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(Node *node, int sum)
{
    // Complete the function
    if (node == NULL)
        return sum == 0;
    sum -= node->val;
    if (node->left == NULL && node->right == NULL)
        return sum == 0;
    return hasPathSum(node->left, sum) || hasPathSum(node->right, sum);
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
        int n, sum;
        cin >> n >> sum;
        assert(n <= 1000000);
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int ind = 0;
        Node *tree = getBinaryTree(arr, &ind);
        if (hasPathSum(tree, sum))
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
