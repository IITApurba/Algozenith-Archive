#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int i = 0;
        while (i < n)
        {
            int start = i;
            cout << s[i++];
            while (s[i++] != s[start])
                ;
        }
        cout << endl;
    }
}