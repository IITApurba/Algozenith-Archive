#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n;
vector<char> InOrder, PreOrder;
map<int, int> mp;

struct node
{
    int data;
    node *left, *right;

    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

node *create(int Lin, int Rin, int Lpre, int Rpre)
{
    if (Lin > Rin)
        return NULL;

    int rootVal = PreOrder[Lpre];
    int brpoint = mp[rootVal];

    node *root = new node(rootVal);
    root->left = create(Lin, brpoint - 1, Lpre + 1, Lpre + (brpoint - Lin));
    root->right = create(brpoint + 1, Rin, Lpre + (brpoint - Lin) + 1, Rpre);

    return root;
}

void printPostorder(node *root)
{
    if (!root)
        return;

    printPostorder(root->left);
    printPostorder(root->right);
    cout << (char)root->data << " ";
}

void solve()
{
    cin >> n;

    InOrder.resize(n);
    PreOrder.resize(n);
    mp.clear();

    for (int i = 0; i < n; i++)
    {
        cin >> InOrder[i];
        mp[InOrder[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> PreOrder[i];
    }

    node *root = create(0, n - 1, 0, n - 1);

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
