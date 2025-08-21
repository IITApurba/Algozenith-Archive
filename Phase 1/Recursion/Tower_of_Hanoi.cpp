#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void move(int diskNum, int source, int destination)
{
    cout << source << " " << destination << "\n";
}

void towerOfHanoi(int n, int source, int destination, int helper)
{
    if (n == 0)
        return;

    // Move n - 1 disks from source to helper using destination
    towerOfHanoi(n - 1, source, helper, destination);

    // Move largest disk from source to destination in one move
    move(n, source, destination);

    // Move n - 1 disks from helper to destination using source
    towerOfHanoi(n - 1, helper, destination, source);
}

void solve()
{
    int n;
    cin >> n;
    cout << (1 << n) - 1 << "\n";
    towerOfHanoi(n, 1, 3, 2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}