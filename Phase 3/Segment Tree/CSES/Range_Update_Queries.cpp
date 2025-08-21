#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

const int Max_size = 2e5 + 10;

struct node
{
    int sum;

    node()
    {
        sum = 0;
    }
};

int n;
int p[Max_size];
node t[4 * Max_size];

node merge(node left, node right)
{
    node ans;
    ans.sum = left.sum + right.sum;
    return ans;
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        t[id].sum = 0;
        return;
    }

    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);

    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

void update(int id, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
        return;

    if (l == r)
    {
        t[id].sum += val;
        return;
    }

    int mid = (l + r) / 2;

    update(2 * id, l, mid, pos, val);
    update(2 * id + 1, mid + 1, r, pos, val);

    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

node query(int id, int l, int r, int lq, int rq)
{
    if (lq > r || l > rq)
        return node();

    if (lq <= l && r <= rq)
        return t[id];

    int mid = (l + r) / 2;

    return merge(
        query(2 * id, l, mid, lq, rq),
        query(2 * id + 1, mid + 1, r, lq, rq));
}

void solve()
{
    int q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    memset(p, 0, sizeof(p));

    build(1, 0, n - 1);

    while (q--)
    {
        int ch;
        cin >> ch;

        if (ch == 1)
        {
            int a, b, u;
            cin >> a >> b >> u;
            a--, b--;

            update(1, 0, n - 1, a, u);
            update(1, 0, n - 1, b + 1, -u);
        }
        else
        {
            int k;
            cin >> k;
            k--;
            node ans = query(1, 0, n - 1, 0, k);

            cout << ans.sum + arr[k] << endl;
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