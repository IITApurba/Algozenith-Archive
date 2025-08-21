#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

// this gives us the bits of the number in string format
string get_bit_string(int x)
{
    string cur = "";
    while (x)
    {
        if (x % 2)
            cur += '1';
        else
            cur += '0';
        x /= 2;
    }

    reverse(cur.begin(), cur.end());
    return cur;
}

// this gives us the number of bits in n from 0-n
int sum_of_bits(int x)
{
    int ans = 0;
    int tot = x + 1;

    for (int i = 0; i < 60; i++)
    {
        int full = (tot / (1LL << (i + 1)));
        int left = (tot % (1LL << (i + 1)));
        int extra = max((left - (1LL << i)), 0LL);
        ans += (full * (1LL << i)) + extra;
    }
    return ans;
}

// this is the binary search code to find the number containing the kth 1
int find_kth_one(int k)
{
    int lo = 0, hi = k;
    int ans = -1;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;

        if (sum_of_bits(mid) >= k)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return ans;
}

// this is to find the index of the kth one in the number found using bs
int find_kth_one_pos_in_num(int x, int k)
{
    int cnt = 0;
    string num = get_bit_string(x);
    int i;
    for (i = 0; i < num.size(); i++)
    {
        if (num[i] == '1')
            cnt++;

        if (cnt == k)
            break;
    }
    return i;
}

// this is to find the total number of bits uptill the number [0,n)
int total_bits_till(int x)
{
    int ans = 0;
    int len = 1;
    int num = 1;

    while (num <= x)
    {
        int sametill = (2 * num) - 1;
        if (sametill <= x)
        {
            ans += len * (sametill - num + 1);
            num = sametill + 1;
            len++;
        }
        else
        {
            ans += len * (x - num + 1);
            break;
        }
    }

    return ans + 1;
}

signed main()
{
    int q;
    cin >> q;

    while (q--)
    {
        int k;
        cin >> k;
        int num = find_kth_one(k);

        int pos_in_num = k - sum_of_bits(num - 1);
        int index = find_kth_one_pos_in_num(num, pos_in_num);
        cout << total_bits_till(num - 1) + index << endl;
    }

    return 0;
}