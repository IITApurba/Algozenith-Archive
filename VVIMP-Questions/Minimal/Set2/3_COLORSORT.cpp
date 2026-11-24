/*
  Problem : COLORSORT
  Link    : https://maang.in/problems/COLORSORT-630
  Given   : Array of N elements containing only 0, 1, 2.
  Find    : The sorted array (sort in place).
*/

#include <bits/stdc++.h>
using namespace std;

void sort(int a[], int n)
{
    // Three pointers
    int low = 0;      // Position for the next 0
    int mid = 0;      // Current element being examined
    int high = n - 1; // Position for the next 2

    while (mid <= high)
    {
        if (a[mid] == 0)
        {
            // Move 0 to the left side
            swap(a[low], a[mid]);

            // Both positions are now processed
            low++;
            mid++;
        }
        else if (a[mid] == 1)
        {
            // 1 is already in the correct region
            mid++;
        }
        else
        {
            // Move 2 to the right side
            swap(a[mid], a[high]);

            // Rightmost position is now processed
            high--;

            // Do not increment mid because the swapped
            // element at mid has not been examined yet
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << '\n';

    return 0;
}