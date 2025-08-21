#include <iostream>
using namespace std;

// Node of a Doubly Linked List
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

// Doubly Linked List class
class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at the beginning
    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at the end
    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (!tail)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Delete head node
    void deleteAtHead()
    {
        if (!head)
            return;

        Node *toDelete = head;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        delete toDelete;
    }

    // Delete tail node
    void deleteAtTail()
    {
        if (!tail)
            return;

        Node *toDelete = tail;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete toDelete;
    }

    // Delete node by value (first occurrence)
    void deleteByValue(int val)
    {
        if (!head)
            return;

        Node *curr = head;

        while (curr && curr->data != val)
            curr = curr->next;

        if (!curr)
            return;

        if (curr == head)
            deleteAtHead();
        else if (curr == tail)
            deleteAtTail();
        else
        {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
        }
    }

    // Display from head to tail
    void displayForward()
    {
        Node *temp = head;
        cout << "Forward: ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    // Display from tail to head
    void displayBackward()
    {
        Node *temp = tail;
        cout << "Backward: ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << "\n";
    }

    // Destructor to free memory
    ~DoublyLinkedList()
    {
        Node *temp = head;
        while (temp)
        {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main()
{
    DoublyLinkedList dll;

    dll.insertAtHead(10);
    dll.insertAtTail(20);
    dll.insertAtTail(30);
    dll.insertAtHead(5);

    dll.displayForward();  // Forward: 5 10 20 30
    dll.displayBackward(); // Backward: 30 20 10 5

    dll.deleteByValue(10);
    dll.displayForward(); // Forward: 5 20 30

    dll.deleteAtHead();
    dll.deleteAtTail();
    dll.displayForward(); // Forward: 20

    return 0;
}
