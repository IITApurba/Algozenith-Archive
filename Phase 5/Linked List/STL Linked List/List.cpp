#include <iostream>
#include <list>
using namespace std;

void printList(const list<int> &lst, const string &name = "")
{
    if (!name.empty())
        cout << name << ": ";
    for (int x : lst)
        cout << x << " ";
    cout << "\n";
}

int main()
{
    // 1. Declaration and Initialization
    list<int> l1 = {10, 20, 30};
    list<int> l2(5, 100); // 5 elements with value 100
    list<int> l3(l1);     // Copy constructor

    printList(l1, "l1");
    printList(l2, "l2");
    printList(l3, "l3");

    // 2. push_front, push_back
    l1.push_front(5); // [5, 10, 20, 30]
    l1.push_back(40); // [5, 10, 20, 30, 40]
    printList(l1, "l1 after push");
    
    // 3. pop_front, pop_back
    l1.pop_front(); // removes 5
    l1.pop_back();  // removes 40
    printList(l1, "l1 after pop");

    // 4. front, back
    cout << "Front: " << l1.front() << ", Back: " << l1.back() << "\n";

    // 5. insert at position
    auto it = l1.begin();
    advance(it, 1);    // move to 2nd position
    l1.insert(it, 15); // insert before 2nd element
    printList(l1, "l1 after insert");

    // 6. erase at position
    it = l1.begin();
    advance(it, 2);
    l1.erase(it); // remove element at 3rd position
    printList(l1, "l1 after erase");

    // 7. remove by value
    l1.push_back(20); // add duplicate
    l1.remove(20);    // removes all 20s
    printList(l1, "l1 after remove(20)");

    // 8. unique (remove consecutive duplicates)
    list<int> l4 = {1, 1, 2, 2, 2, 3, 3, 4};
    l4.unique();
    printList(l4, "l4 after unique");

    // 9. reverse
    l4.reverse();
    printList(l4, "l4 after reverse");

    // 10. sort
    list<int> l5 = {4, 1, 3, 2};
    l5.sort();
    printList(l5, "l5 after sort");

    // 11. merge
    list<int> l6 = {1, 3, 5};
    list<int> l7 = {2, 4, 6};
    l6.merge(l7); // merges l7 into l6 (both must be sorted)
    printList(l6, "l6 after merge");
    printList(l7, "l7 after merge (should be empty)");

    // 12. splice (move elements from one list to another)
    list<int> l8 = {1, 2, 3};
    list<int> l9 = {10, 20};
    auto pos = l8.begin();
    advance(pos, 1);
    l8.splice(pos, l9); // move l9 into l8 at 2nd position
    printList(l8, "l8 after splice");
    printList(l9, "l9 after splice (should be empty)");

    // 13. clear, empty, size
    l1.clear();
    cout << "l1 size: " << l1.size() << ", is empty? " << boolalpha << l1.empty() << "\n";

    return 0;
}
