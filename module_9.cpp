#include <bits/stdc++.h>
using namespace std;

// *List: The C++ std::list is a sequence container that implements a doubly linked list, allowing for efficient insertions and deletions of elements at any position within the sequence. It is part of the Standard Template Library (STL) and is defined in the <list> header file.

// %1. Constructor
// i.list<type> list_name; : Construct a list with 0 elements. O(1)
// ii. list<type> list_name(N); : Construct a list with N elements (values will be garbage). O(N)
// iii. list<type> list_name(N, V); : Construct a list with N elements, all having value V. O(N)
// iv. list<type> list_name(list2); : Construct a list by copying another list list2. O(N)
// v. list<type> list_name(A, A+N); : Construct a list by copying all elements from an array A of size N. O(N)
// vi. list<type> list_name(v.begin(), v.end()); : Construct a list by copying all elements from a vector v. O(N)

// %2. Capacity
// i. list_name.size() : Returns the current size of the list. O(1)
// ii. list_name.max_size() : Returns the maximum size that the list can hold. O(1)
// iii. list_name.clear() : Clears all elements from the list. O(N)
// iv. list_name.empty() : Returns true if the list is empty, false otherwise. O(1)
// v. list_name.resize() : Change the size of the list. O(K) (where K is the difference between new size and current size).

// %3. Modifiers
// i. list_name = or list_name.assign(list2.begin(), list2.end()) : Assign another list's elements to this list. O(N)
// ii. list_name.push_back(value) : Add an element to the tail. O(1)
// iii. list_name.push_front(value) : Add an element to the head. O(1)
// iv. list_name.pop_back() : Delete the tail element. O(1)
// v. list_name.pop_front() : Delete the head element. O(1)
// vi. list_name.insert(next(list_name.begin(), i), value) : Insert an element at the i-th position. O(N + K) (where K is the number of elements to be inserted).
// vii. list_name.erase(next(list_name.begin(), i)) : Delete the element at the i-th position. O(N + K) (where K is the number of elements to be deleted).
// viii. replace(list_name.begin(), list_name.end(), value, replace_value) : Replace all instances of value with replace_value. (Non-member function). O(N)
// ix. find(list_name.begin(), list_name.end(), V) : Find the position of value V. (Non-member function). O(N)

// %4. Operations
// i. list_name.remove(V) : Remove all instances of the value V from the list. O(N)
// ii. list_name.sort() : Sort the list in ascending order. O(NlogN)
// iii. list_name.sort(greater<type>()) : Sort the list in descending order. O(NlogN)
// iv. list_name.unique() : Deletes duplicate values (List must be sorted first). O(N) (with sort it becomes O(NlogN)).
// v. list_name.reverse() : Reverse the order of elements in the list. O(N)

// %5. Element Access
// i. list_name.back() : Access the tail element. O(1)
// ii. list_name.front() : Access the head element. O(1)
// iii. next(list_name.begin(), i) : Access the iterator pointing to the i-th element. To print the element, dereference the iterator. O(N)

// %6. Iterators
// i. list_name.begin() : Returns an iterator pointing to the first element. Dereference to access the element. front() also provides the same functionality. O(1)
// ii. list_name.end() : Returns an iterator pointing to the theoretical element after the last element. Dereference to access the element. back() provides access to the last element whereas end() points to the next position after the last element. O(1)

class Node
{
public:
    int value;
    Node *prev;
    Node *next;

    Node(int val)
    {
        this->value = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void reverse_doubly_linked_list(Node *head, Node *tail)
{
    for (Node *i = head, *j = tail; i != j && i->prev != j; i = i->next, j = j->prev)
    {
        swap(i->value, j->value); // Why just swapping values? Because head and tail does not need to change, only the values are swapped to achieve the reverse effect.
        // A<=>B<=>C<=>D<=>E, here head points to A and tail points to E
        // After first iteration: E<=>B<=>C<=>D<=>A
        // After second iteration: E<=>D<=>C<=>B<=>A,  as we do not change the head and tail pointers, they still point to A and E respectively; so head is still at the start and tail is still at the end.
    }
};

void print_forward(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    list<int> l(10, 3);
    for (int x : l)
    { // It can written as for(auto it=l.begin(); it!=l.end(); it++) also
        cout << x << " ";
    }
    cout << endl;

    cout << "Second element: " << *next(l.begin(), 1) << endl; // Accessing 2nd element

    list<int> l2 = {15, 20, 65};

    l.insert(next(l.begin(), 2), l2.begin(), l2.end());  // Inserting l2 at position 2 of l
    l.erase((next(l.begin(), 4)), (next(l.begin(), 6))); // Deleting elements from index 4 to 5 (6-1)

    auto it = find(l.begin(), l.end(), 20);
    if (it == l.end())
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << "Found: " << *it << endl; // Why dereferencing is needed? because 'it' is an iterator pointing to the element, same as next().
    }

    Node *head = NULL;
    Node *tail = NULL;

    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    cout << "Original DLL: ";
    print_forward(head);
    reverse_doubly_linked_list(head, tail);
    cout << "Reversed DLL: ";
    print_forward(head);
    return 0;
}