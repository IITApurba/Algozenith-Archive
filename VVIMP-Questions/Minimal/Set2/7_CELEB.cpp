#include <bits/stdc++.h>
using namespace std;


int FindCeleb(vector<vector<int>> &a)
{
    int n=a.size();
    vector<int> indeg(n),outdeg(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            indeg[j]+=a[i][j];
            outdeg[i]+=a[i][j];
        }
    }
    int count=0,celeb=-1;
    for(int i=0;i<n;i++)
    {
        count+=(indeg[i]==n-1 && outdeg[i]==0);
        if(indeg[i]==n-1 && outdeg[i]==0)celeb=i;
    }
    if(count==1)
    {
        return celeb+1;
    }
    else
    {
        return -1;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << FindCeleb(a) << '\n';
}