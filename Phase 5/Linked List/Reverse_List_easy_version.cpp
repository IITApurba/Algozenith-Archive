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

Node *head;

void reverse(Node *p)
{
    if (p->next == NULL)
    {
        head = p;
        return;
    }
    reverse(p->next);
    p->next->next = p;
    p->next = NULL;
}

void solve()
{
    int n;
    cin >> n;
    head = new Node();
    head->data = 1;
    Node *temp = head;
    for (int i = 2; i <= n; i++)
    {
        Node *newNode = new Node();
        newNode->data = i;
        temp->next = newNode;
        temp = newNode;
    }
    temp->next = NULL;
    reverse(head);

    // Print the reversed linked list
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
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