#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:

    LinkedList()
    {
        head = nullptr;
    }

    void insert(int data)
    {

    }

    void printList()
    {

    }

    int size()
    {

    }

    void removeNthFromEnd(int n)
    {
        
    }
};

void solve()
{
    int n;
    cin >> n;

    LinkedList list;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        list.insert(data);
    }

    int k;
    cin >> k;

    list.removeNthFromEnd(k);
    list.printList();
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}
