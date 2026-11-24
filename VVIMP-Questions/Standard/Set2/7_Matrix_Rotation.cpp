#include <bits/stdc++.h>
using namespace std;


void RotateMatrix(vector<vector<int>> &v)
{
    int n = v[0].size();
    //transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            swap(v[i][j],v[j][i]);
        }
    }

    // reverse each row
    for (int i = 0; i < n; i++)
    {
        reverse(v[i].begin(),v[i].end());
    }
    
    
}


int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    }

    RotateMatrix(v);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << v[i][j] << " ";
        cout << "\n";
    }
}
