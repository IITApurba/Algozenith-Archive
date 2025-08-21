#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList()
    {
        head = nullptr;
    }

    // Insert at end
    void insert(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    // Function to find the length
    int length()
    {
        if (!head)
            return 0;

        int count = 1;
        Node *temp = head->next;

        while (temp != head)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // Destructor to free memory
    ~CircularLinkedList()
    {
        if (!head)
            return;

        Node *curr = head->next;
        while (curr != head)
        {
            Node *next = curr->next;
            delete curr;
            curr = next;
        }
        delete head;
    }
};
int main()
{
    CircularLinkedList cll;
    cll.insert(10);
    cll.insert(20);
    cll.insert(30);

    cout << "Length of Circular Linked List: " << cll.length() << endl; // Output: 3

    return 0;
}
