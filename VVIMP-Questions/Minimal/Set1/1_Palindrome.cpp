#include <bits/stdc++.h>
using namespace std;

#define int long long

string s;
int n;

bool help(int start, int end){

    while (start<end)
    {
        if(s[start]!=s[end])
            return false;

        start++;
        end--;
    }
    return true;
}


void solve()
{
    cin >> s;
    n = s.length();

    for(int i = 0 ; i < n ; i++){

        if(s[i]!=s[n-1-i]) // char is not matching
        {
            // so chances are there removing this ith element
            // or the n-i-2 th element
            // we can get a palindrome
            if(help(i+1,n-1-i) || help(i,n-1-i-1)){
                cout << "Y" << endl;
                return;
            }
            else {
                cout << "N" << endl;
                return;
            }
        }
    }


    cout << "Y" << endl;

    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}