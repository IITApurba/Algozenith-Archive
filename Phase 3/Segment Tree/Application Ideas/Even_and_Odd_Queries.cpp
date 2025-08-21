#include <bits/stdc++.h>
using namespace std;

#define int long long

const int Max_size = 2e5 + 10;

struct Node
{
    int even, odd;
    Node(int e = 0, int o = 0)
    {
        even = e;
        odd = o;
    }
};

int n;
int arr[Max_size];
Node t[4 * Max_size];

Node merge(Node a, Node b)
{
    return Node(a.even + b.even, a.odd + b.odd);
}

void build(int index, int l, int r)
{
    if (l == r)
    {
        if (arr[l] % 2 == 0)
            t[index] = Node(1, 0);
        else
            t[index] = Node(0, 1);
        return;
    }

    int mid = (l + r) / 2;
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);

    t[index] = merge(t[2 * index], t[2 * index + 1]);
}

void update(int index, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
        return;

    if (l == r)
    {
        if (val % 2 == 0)
            t[index] = Node(1, 0);
        else
            t[index] = Node(0, 1);
        arr[l] = val;
        return;
    }

    int mid = (l + r) / 2;
    update(2 * index, l, mid, pos, val);
    update(2 * index + 1, mid + 1, r, pos, val);

    t[index] = merge(t[2 * index], t[2 * index + 1]);
}

Node query(int index, int l, int r, int lq, int rq)
{
    if (l > rq || r < lq)
        return Node(0, 0);

    if (lq <= l && r <= rq)
        return t[index];

    int mid = (l + r) / 2;
    Node left_query = query(2 * index, l, mid, lq, rq);
    Node right_query = query(2 * index + 1, mid + 1, r, lq, rq);

    return merge(left_query, right_query);
}

void solve()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    int q;
    cin >> q;

    build(1, 1, n);

    while (q--)
    {
        int ch;
        cin >> ch;
        if (ch == 0)
        {
            int pos, val;
            cin >> pos >> val;
            update(1, 1, n, pos, val);
        }
        else if (ch == 1)
        {
            int l, r;
            cin >> l >> r;
            Node res = query(1, 1, n, l, r);
            cout << res.even << endl;
        }
        else if (ch == 2)
        {
            int l, r;
            cin >> l >> r;
            Node res = query(1, 1, n, l, r);
            cout << res.odd << endl;
        }
    }
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
