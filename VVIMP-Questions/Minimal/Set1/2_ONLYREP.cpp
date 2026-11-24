#include <bits/stdc++.h>
using namespace std;

int FindRepeated(vector<int> &a)
{
    // Complete the function
    // a contains elements from 1 to N-1
    // though its size is N
    // it should contain 1 to N but one element is repeating
    // so it is not 1 to N-1

    int XOR_Array = 0;
    int XOR_1toN = 0;

    for (int i = 0; i < a.size(); i++)
    {
        XOR_Array = XOR_Array ^ a[i];
    }

    for (int i = 1; i < a.size(); i++)
    {
        XOR_1toN = XOR_1toN ^ i;
    }

    int element = XOR_Array ^ XOR_1toN;

    return element;
}

int FindRepeated1(vector<int> &a)
{
    long long sum=accumulate(a.begin(),a.end(),0LL);
    long long n=a.size();
    long long nSum=(n*(n+1))/2;
    return sum-nSum+n;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << FindRepeated(a) << "\n";
}
