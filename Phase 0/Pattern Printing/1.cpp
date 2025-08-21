#include <bits/stdc++.h>
using namespace std;

// .  .  .  *  .  .  .  
// .  .  .  *  .  .  .  
// .  .  .  *  .  .  .  
// *  *  *  *  *  *  *  
// .  .  .  *  .  .  .  
// .  .  .  *  .  .  .  
// .  .  .  *  .  .  .  

void fun(int i, int j, int n, int m) {

    if(i == n/2  || j == m/2)
        cout << "*  ";
    else    
        cout << ".  ";
}

int main() {

    int n = 7, m = 7;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fun(i, j,n,m);
        }
        cout << endl;
    }
    

    return 0;
}