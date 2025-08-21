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

public:
    BinaryTree() : root(nullptr) {}

    void constructTree(vector<int> &arr)
    {
        int index = 0;
        root = buildTree(arr, index);
    }

    vector<vector<int>> getDiagonalOrder()
    {
        vector<vector<int>> result;
        if (!root)
            return result;

        queue<pair<Node *, int>> q;
        map<int, vector<int>> diagMap;

        q.push({root, 0});

        while (!q.empty())
        {
            auto [node, d] = q.front();
            q.pop();

            diagMap[d].push_back(node->val);

            if (node->left)
                q.push({node->left, d + 1});
            if (node->right)
                q.push({node->right, d});
        }

        for (auto &[_, vec] : diagMap)
            result.push_back(vec);

        return result;
    }
};

void print2D(const vector<vector<int>> &v)
{
    for (const auto &level : v)
    {
        for (int x : level)
            cout << x << " ";
        cout << "\n";
    }
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
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        BinaryTree tree;
        tree.constructTree(arr);
        auto result = tree.getDiagonalOrder();
        reverse(result.begin(), result.end());
        print2D(result);
        cout << endl;
    }

    return 0;
}
