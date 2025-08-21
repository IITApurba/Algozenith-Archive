#include <iostream>
using namespace std;

int main()
{
    int a = 2147483647;
    int b = 2147483647;
    int res1 = (a + b) % a;
    int res2 = (a - b) % a;
    cout << res1 << " " << res2;
}
