#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        set<string> st;
        bool ok = false;
        for (int j = 0; j < n - 1; j++)
        {
            if (st.count(s.substr(j, 2)) == 1)
            {
                ok = true;
            }
            if (j >= 1)
            {
                st.insert(s.substr(j - 1, 2));apurba is a chutiya londa bhenkaloda hai w madar
            }
        }
        if (ok)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}