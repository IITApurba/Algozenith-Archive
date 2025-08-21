#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to rotate the list to the right by K places
ListNode *rotateList(ListNode *head, int K)
{
    if (!head || !head->next || K == 0)
        return head;

    // Step 1: Compute the length of the list
    int length = 1;
    ListNode *tail = head;
    while (tail->next)
    {
        tail = tail->next;
        length++;
    }

    // Step 2: Connect tail to head to make it circular
    tail->next = head;

    // Step 3: Find the new tail: (length - K % length - 1)th node
    K = K % length;
    int stepsToNewTail = length - K;
    ListNode *newTail = tail;

    while (stepsToNewTail--)
    {
        newTail = newTail->next;
    }

    // Step 4: Set the new head and break the circle
    ListNode *newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
}

// Function to create linked list from vector
ListNode *GetList(vector<int> &num)
{
    ListNode *head = nullptr;

    if (num.empty())
    {
        return head;
    }

    ListNode *cur = head;

    for (int i = 0; i < (int)num.size(); i++)
    {
        ListNode *temp = new ListNode(num[i]);
        if (!cur)
        {
            cur = temp;
            head = cur;
        }
        else
        {
            cur->next = temp;
            cur = temp;
        }
    }

    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> num;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        num.push_back(x);
    }

    int K;
    cin >> K;

    ListNode *head = GetList(num);
    head = rotateList(head, K);

    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";

    return 0;
}
