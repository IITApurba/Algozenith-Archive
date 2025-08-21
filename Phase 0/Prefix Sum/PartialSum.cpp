#include <bits/stdc++.h>
using namespace std;

int main()
{

    int N, Q;
    cin >> N >> Q;

    vector<int> array(N, 0);

    while (Q--)
    {
        int L, R, x;
        cin >> L >> R >> x;

        array[L - 1] += x;
        if (R < N)
            array[R] -= x;
    }

    for (int i = 1; i < N; i++)
    {
        array[i] += array[i - 1];
    }

    printf("Array after queries: ");
    for (int i = 0; i < N; i++)
        cout << array[i] << " ";

    cout << endl;
    return 0;
}