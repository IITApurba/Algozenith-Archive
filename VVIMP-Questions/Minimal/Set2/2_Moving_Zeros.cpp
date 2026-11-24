/*
  Problem : Moving Zeros
  Link    : https://maang.in/problems/Moving-Zeros-597
  Given   : Integer array nums.
  Find    : Move all zeros to the end in place, keeping the order of the rest (O(1) space, few swaps).
*/

#include <bits/stdc++.h>
using namespace std;

void MovingZeros(vector<int> &nums)
{

    int pos_of_leftmost_zero = 0;
    for (int array_pos = 0; array_pos < nums.size(); array_pos++)
    {
        if (nums[array_pos] != 0)
        {
            swap(nums[array_pos], nums[pos_of_leftmost_zero]);
            pos_of_leftmost_zero++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &i : nums)
        cin >> i;
    MovingZeros(nums);
    for (auto i : nums)
        cout << i << " ";
}