#include <bits/stdc++.h>
using namespace std;

vector<int> FindRepeated(vector<int> &arr)
{
    int x = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        x ^= arr[i];
    }

    int bit = x & (-x);

    int grp1_xor = 0, grp2_xor = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] & bit)
            grp1_xor ^= arr[i];
        else
            grp2_xor ^= arr[i];
    }

    int A = grp1_xor, B = grp2_xor;

    if (A > B)
        swap(A, B);

    return {A, B};
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(2 * n + 2);

    for (int i = 0; i < 2 * n + 2; i++)
        cin >> a[i];

    vector<int> ans = FindRepeated(a);
    cout << ans[0] << " " << ans[1] << "\n";
}
