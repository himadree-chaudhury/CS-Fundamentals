#include <bits/stdc++.h>
using namespace std;

// Array Limitation:
// -Fixed Size: Arrays have a fixed size determined at the time of their declaration, which cannot be changed during runtime. This problem can be solved using dynamic arrays or data structures like vectors.
// -Sequential Memory Allocation: Arrays allocate memory in a contiguous block, which can lead to memory fragmentation and inefficient use of space, especially for large arrays with many unused elements. This can be mitigated by using linked lists or other dynamic data structures that allocate memory as needed.

class Node
{
public:
    int value;
    Node *next;

    Node(int val)
    {
        this->value = val;
        this->next = NULL;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << (int)&arr[2] << " " << (int)&arr[3] << endl; // Address of arr[2] and arr[3] are contiguous in memory

    // *Linked List(singly linked list): A linked list is a linear data structure where each element (node) contains a value and a pointer to the next node in the sequence. The final element points to null. Unlike arrays, linked lists do not require contiguous memory allocation, allowing for dynamic resizing and efficient insertions and deletions. However, they have higher memory overhead due to storing pointers and can have slower access times since elements are not stored in contiguous memory locations. Why it is called singly linked list? Because each node contains a pointer to the next node only.

    // Steps to implement a singly linked list:
    // 1. Define a Node structure that contains data and a pointer to the next node using class/struct.
    // 2. In the class, there will be value and a pointer to the next node. So the type of the pointer will be of the same class type as it pointing to the next node.


    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    head->next = second;        // ALso can be decelared as head->next = new Node(20); without creating separate pointer
    second->next = third;   

    cout << head->value << " " << head->next->value << " " << head->next->next->value << endl;   // This way is terrible for large linked list as we have to traverse each time.

    Node *temp = head;      // Use a temporary pointer so that we don't lose the head pointer
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;      // How this works: Initially temp points to head. In each iteration, we print the value at temp and then move temp to the next node using temp = temp->next. This continues until temp becomes NULL, indicating the end of the linked list.
    }

    temp = head;
    
    return 0;
}