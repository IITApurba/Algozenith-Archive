#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;

bool palindrome(string s , int f , int l)
{
    if(s[f] != s[l])
        return false;
    if(f >= l)
        return true;
    return palindrome(s , f+1 , l-1);
}

void solve()
{
    string s;
    cin >> s;

    if(palindrome(s , 0 , s.size()-1))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

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