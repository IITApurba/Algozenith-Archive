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

    // Preorder Traversal (Root, Left, Right)
    void preorder(Node *node, vector<int> &result)
    {
        if (!node)
            return;
        result.push_back(node->val);
        preorder(node->left, result);
        preorder(node->right, result);
    }

    // Inorder Traversal (Left, Root, Right)
    void inorder(Node *node, vector<int> &result)
    {
        if (!node)
            return;
        inorder(node->left, result);
        result.push_back(node->val);
        inorder(node->right, result);
    }

    // Postorder Traversal (Left, Right, Root)
    void postorder(Node *node, vector<int> &result)
    {
        if (!node)
            return;
        postorder(node->left, result);
        postorder(node->right, result);
        result.push_back(node->val);
    }

    vector<vector<int>> getLevelOrderTraversal()
    {
        vector<vector<int>> result;
        if (!root)
            return result;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int sz = q.size();
            vector<int> level;
            for (int i = 0; i < sz; ++i)
            {
                Node *cur = q.front();
                q.pop();
                level.push_back(cur->val);

                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            result.push_back(level);
        }
        return result;
    }

    vector<vector<int>> ZigzagLevelorderTraversal()
    {
        vector<vector<int>> result;
        if (!root)
            return result;

        queue<Node *> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty())
        {
            int levelSize = q.size();
            vector<int> level(levelSize);

            for (int i = 0; i < levelSize; ++i)
            {
                Node *current = q.front();
                q.pop();
                int index = leftToRight ? i : (levelSize - 1 - i);
                level[index] = current->val;

                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }

            result.push_back(level);
            leftToRight = !leftToRight;
        }

        return result;
    }

    vector<vector<int>> verticalTraversal()
    {
        map<int, map<int, multiset<int>>> nodes; // col -> row -> multiset of vals
        queue<tuple<Node *, int, int>> q;        // node, row, col

        if (root)
            q.push({root, 0, 0});

        while (!q.empty())
        {
            auto [node, row, col] = q.front();
            q.pop();
            nodes[col][row].insert(node->val);

            if (node->left)
                q.push({node->left, row + 1, col - 1});
            if (node->right)
                q.push({node->right, row + 1, col + 1});
        }

        vector<vector<int>> result;
        for (auto &[col, rowMap] : nodes)
        {
            vector<int> colVals;
            for (auto &[row, multisetVals] : rowMap)
            {
                colVals.insert(colVals.end(), multisetVals.begin(), multisetVals.end());
            }
            result.push_back(colVals);
        }

        return result;
    }

    vector<vector<int>> DiagonalLevelorderTraversal()
    {
        map<int, vector<int>> diagonalMap;
        queue<pair<Node *, int>> q;

        if (root)
            q.push({root, 0}); // node, diagonalLevel

        while (!q.empty())
        {
            auto [node, diag] = q.front();
            q.pop();

            diagonalMap[diag].push_back(node->val);

            if (node->left)
                q.push({node->left, diag + 1});
            if (node->right)
                q.push({node->right, diag});
        }

        vector<vector<int>> result;
        for (auto &[d, vec] : diagonalMap)
        {
            result.push_back(vec);
        }

        return result;
    }

    // Accessor methods
    vector<int> getPreorder()
    {
        vector<int> res;
        preorder(root, res);
        return res;
    }

    vector<int> getInorder()
    {
        vector<int> res;
        inorder(root, res);
        return res;
    }

    vector<int> getPostorder()
    {
        vector<int> res;
        postorder(root, res);
        return res;
    }

    vector<vector<int>> getLevelOrder()
    {
        return getLevelOrderTraversal();
    }

    vector<vector<int>> getZigzagOrder()
    {
        return ZigzagLevelorderTraversal();
    }

    vector<vector<int>> getVerticalOrder()
    {
        return verticalTraversal();
    }

    vector<vector<int>> getDiagonalOrder()
    {
        return DiagonalLevelorderTraversal();
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

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    BinaryTree tree;
    tree.constructTree(arr);

    auto pre = tree.getPreorder();
    auto in = tree.getInorder();
    auto post = tree.getPostorder();
    auto level = tree.getLevelOrder();
    auto zigzag = tree.getZigzagOrder();
    auto vertical = tree.getVerticalOrder();
    auto diagonal = tree.getDiagonalOrder();

    cout << "Preorder: ";
    for (int x : pre)
        cout << x << " ";
    cout << "\n";

    cout << "Inorder: ";
    for (int x : in)
        cout << x << " ";
    cout << "\n";

    cout << "Postorder: ";
    for (int x : post)
        cout << x << " ";
    cout << "\n";

    cout << "Level Order:\n";
    print2D(level);

    cout << "Zigzag Order:\n";
    print2D(zigzag);

    cout << "Vertical Order:\n";
    print2D(vertical);

    cout << "Diagonal Order:\n";
    print2D(diagonal);

    return 0;
}
