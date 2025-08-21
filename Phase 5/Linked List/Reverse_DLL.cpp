#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList()
    {
        head = nullptr;
    }

    // Insert at the end
    void insert(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Display forward
    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    // Reverse the entire list
    void reverseFull()
    {
        Node *curr = head;
        Node *temp = nullptr;

        while (curr)
        {
            // Swap prev and next
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }

        // Update head
        if (temp)
            head = temp->prev;
    }

    // Reverse from position L to R (1-based)
    void reversePart(int L, int R)
    {
        if (L >= R || !head)
            return;

        Node *curr = head;
        int pos = 1;

        // Step 1: Reach position L
        while (curr && pos < L)
        {
            curr = curr->next;
            pos++;
        }

        Node *beforeL = curr->prev;
        Node *left = curr;

        // Step 2: Reach position R
        while (curr && pos < R)
        {
            curr = curr->next;
            pos++;
        }

        Node *right = curr;
        Node *afterR = right->next;

        // Step 3: Reverse between left and right
        Node *p = left;
        Node *q = nullptr;

        while (p != afterR)
        {
            q = p->prev;
            p->prev = p->next;
            p->next = q;
            p = p->prev;
        }

        // Step 4: Reconnect
        if (beforeL)
            beforeL->next = right;
        else
            head = right;

        right->prev = beforeL;

        if (afterR)
            left->next = afterR;
        afterR->prev = left;
    }
};

int main()
{
    DoublyLinkedList dll;

    for (int i = 1; i <= 6; i++)
        dll.insert(i); // 1 2 3 4 5 6

    cout << "Original: ";
    dll.display();

    dll.reverseFull();
    cout << "Fully Reversed: ";
    dll.display();

    dll.reversePart(2, 5); // Reverse nodes 2 to 5 (positions, not values)
    cout << "Partially Reversed (2 to 5): ";
    dll.display();

    return 0;
}
