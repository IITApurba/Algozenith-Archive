/*
  Problem : Stone Jumps
  Link    : https://maang.in/problems/Stone-Jumps-616
  Given   : n stones, a[i] = max jump length from stone i; start at stone 1.
  Find    : Can you reach stone n? (Yes / No)
*/

#include <bits/stdc++.h>
using namespace std;


bool isReach(vector<int> jump)
{
	// Complete the function
    int furthest=0;
    for(int i=0;i<jump.size();i++)
    {
        if(i>furthest)
        {
            return false;
        }
        furthest=max(furthest,i+jump[i]);
    }
    return true;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> jump(n);
	for (auto &i : jump)
		cin >> i;

	if (isReach(jump))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}