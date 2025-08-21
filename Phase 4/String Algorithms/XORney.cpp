#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

class KMP
{
public:
    // Build prefix (pi) array for pattern P[0..m-1]
    vector<int> computePrefix(const vector<int> &P)
    {
        int m = P.size();
        vector<int> pi(m + 1);
        pi[0] = -1;
        int i = 0, j = -1;
        while (i < m)
        {
            while (j != -1 && P[i] != P[j])
                j = pi[j];
            i++;
            j++;
            pi[i] = j;
        }
        return pi;
    }
};

void solve()
{
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < N; i++)
        cin >> b[i];

    if (N == 1)
    {
        cout << 0 << " " << (a[0] ^ b[0]) << "\n";
        return;
    }

    // Build neighbor‐XOR difference arrays V and U
    vector<int> V(N), U(N);
    for (int i = 0; i < N; i++)
    {
        V[i] = a[i] ^ a[(i + 1) % N];
        U[i] = b[i] ^ b[(i + 1) % N];
    }

    // Prepare text T = V + V
    vector<int> T(2 * N);
    for (int i = 0; i < 2 * N; i++)
        T[i] = V[i % N];

    // Run KMP: find all occurrences of U in T
    KMP kmp;
    auto pi = kmp.computePrefix(U);
    vector<pair<int, int>> ans;
    int j = 0;
    for (int i = 0; i < 2 * N; i++)
    {
        while (j != -1 && (j == (int)U.size() || T[i] != U[j]))
            j = pi[j];
        i++, j++;
        if (j == (int)U.size())
        {
            int k = i - j;
            // valid shift only if k < N
            if (k < N)
            {
                int x = a[k] ^ b[0];
                ans.emplace_back(k, x);
            }
            j = pi[j];
        }
        // step i back by one because of manual i++ above
        i--;
    }

    sort(ans.begin(), ans.end());
    for (auto &p : ans)
        cout << p.first << " " << p.second << "\n";
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
