#include <bits/stdc++.h>
#include "debug_template.cpp"
using namespace std;

const int MAXN = 500;
int a[MAXN][MAXN];
int P[MAXN][MAXN];

void computePrefixSum(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            P[i][j] = a[i][j];

            if (i > 0)
                P[i][j] += P[i - 1][j];
            if (j > 0)
                P[i][j] += P[i][j - 1];
            if (i > 0 && j > 0)
                P[i][j] -= P[i - 1][j - 1];
        }
    }
}

int queryRectangleSum(int U, int L, int D, int R)
{

    int ans = P[D][R];

    if (L > 0)
        ans -= P[D][L - 1];
    if (U > 0)
        ans -= P[U - 1][R];
    if (U > 0 && L > 0)
        ans += P[U - 1][L - 1];

    return ans;
}

int main()
{

    int n, m;
    cin >> n >> m;

    cout << "Enter the values of the 2D array:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    computePrefixSum(n, m);

    debug(a);
    debug(P);

    int Q;
    cout << "Enter the number of Queries?: ";
    cin >> Q;

    while (Q--)
    {
        int U, L, D, R;
        cout << "Enter query " << " (U L D R): ";
        cin >> U >> L >> D >> R;

        int result = queryRectangleSum(U, L, D, R);
        cout << "The Sum in the rectangle is -> " << result << endl;
    }

    return 0;
}