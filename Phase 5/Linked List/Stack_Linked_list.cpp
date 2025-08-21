#include <iostream>
using namespace std;

// Node class for Linked List
class Node
{
public:
    int data;
    Node *next;

    // Constructor to initialize node
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Stack class using Linked List
class Stack
{
private:
    Node *top; // Points to top of stack

public:
    // Constructor to initialize stack
    Stack()
    {
        top = nullptr;
    }

    // Push element on top of stack
    void push(int x)
    {
        Node *newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    // Pop top element
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n";
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
    }

    // Peek top element
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty()
    {
        return top == nullptr;
    }

    // Destructor to free memory
    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

int main()
{
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top Element: " << st.peek() << endl; // 30

    st.pop();
    cout << "Top after pop: " << st.peek() << endl; // 20

    st.pop();
    st.pop();
    st.pop(); // Should say underflow

    return 0;
}
