
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

int getKthElement(Node *node, int k)
{
    // Complete the function
    if (node == NULL)
        return -1;
    stack<Node *> s;
    Node *curr = node;
    int count = 0;
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        count++;
        if (count == k)
            return curr->val;
        curr = curr->right;
    }
    return -1;
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
        int n, q;
        cin >> n >> q;
        assert(n <= 1000000);
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int ind = 0;
        Node *tree = getBinaryTree(arr, &ind);
        for (int i = 0; i < q; i++)
        {
            int k;
            cin >> k;
            cout << getKthElement(tree, k) << " ";
        }
        cout << "\n";
    }
    return 0;
}
