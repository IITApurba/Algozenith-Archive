#include <bits/stdc++.h>
using namespace std;

#define int long long

const int Max_size = 2e5 + 10;

int n;
int arr[Max_size];
int t[4 * Max_size];

void build(int index, int l, int r)
{
    if (l == r)
    {
        t[index] = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);

    t[index] = t[2 * index] + t[2 * index + 1];
}

void update(int index, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
        return;

    if (l == r)
    {
        t[index] = val;
        arr[l] = val;
        return;
    }

    int mid = (l + r) / 2;
    update(2 * index, l, mid, pos, val);
    update(2 * index + 1, mid + 1, r, pos, val);

    t[index] = t[2 * index] + t[2 * index + 1];
}

int query(int index, int l, int r, int lq, int rq)
{
    if (l > rq || lq > r)
        return 0;

    if (lq <= l && r <= rq)
        return t[index];

    int mid = (l + r) / 2;
    int left_query = query(2 * index, l, mid, lq, rq);
    int right_query = query(2 * index + 1, mid + 1, r, lq, rq);

    return left_query + right_query;
}

void solve()
{
    int q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    build(1, 1, n);

    while (q--)
    {
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            int pos, val;
            cin >> pos >> val;
            update(1, 1, n, pos, val);
        }
        else if (ch == 2)
        {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
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
