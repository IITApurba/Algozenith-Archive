#include <iostream>
using namespace std;

// Node class for doubly linked list
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

// Deque class
class Deque
{
private:
    Node *head;
    Node *tail;
    int count;

public:
    Deque()
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    // Insert at front
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        count++;
    }

    // Insert at back
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (!tail)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
    }

    // Remove from front
    void pop_front()
    {
        if (is_empty())
        {
            cout << "Deque Underflow at Front\n";
            return;
        }
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
        count--;
    }

    // Remove from back
    void pop_back()
    {
        if (is_empty())
        {
            cout << "Deque Underflow at Back\n";
            return;
        }
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
        count--;
    }

    // Get front value
    int get_front()
    {
        if (is_empty())
        {
            cout << "Deque is Empty\n";
            return -1;
        }
        return head->data;
    }

    // Get back value
    int get_back()
    {
        if (is_empty())
        {
            cout << "Deque is Empty\n";
            return -1;
        }
        return tail->data;
    }

    // Check if deque is empty
    bool is_empty()
    {
        return count == 0;
    }

    // Get current size
    int size()
    {
        return count;
    }

    // Destructor
    ~Deque()
    {
        while (!is_empty())
        {
            pop_front();
        }
    }
};

int main()
{
    Deque dq;

    dq.push_front(10);
    dq.push_back(20);
    dq.push_front(5);
    dq.push_back(30);

    cout << "Front: " << dq.get_front() << endl; // 5
    cout << "Back: " << dq.get_back() << endl;   // 30

    dq.pop_front(); // removes 5
    dq.pop_back();  // removes 30

    cout << "Front after pops: " << dq.get_front() << endl; // 10
    cout << "Size: " << dq.size() << endl;                  // 2

    return 0;
}
