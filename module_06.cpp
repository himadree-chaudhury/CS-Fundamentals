#include <bits/stdc++.h>
using namespace std;

// Linked List Operations
// Deletion: at head, at tail, at position
// Printing: forward, backward
// Sorting: Ascending, Descending

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

void print_reverse(Node *head);
void delete_at_head(Node *&head);
void delete_at_position(Node *head, int idx);
void delete_at_tail(Node *head, Node *&tail, int idx);
void sort_linked_list(Node *head);

int main()
{
    // Make liked list from input
    Node *head = NULL;
    Node *tail = NULL;

    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
            break; // Normally to end the input -1 is used

        // Adding new node in the linked list is as same as add node at the tail. If the complexity of adding node at tail is O(n) (using loop) then the overall complexity will be O(n^2), so the tail pointer is used to reduce the complexity to O(1). As a result the overall complexity will be O(n).
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Delete at tail
    delete_at_tail(head, tail, 5);

    // Delete at head
    delete_at_head(head);

    // Delete at position
    delete_at_position(head, 1);

    // Sort the linked list
    sort_linked_list(head);

    // Print the linked list in reverse order using recursion
    print_reverse(head);
    return 0;
}

void print_reverse(Node *head) // Complexity O(n)
{
    if (head == NULL)
        return;

    print_reverse(head->next);
    cout << head->value << " ";
}

void delete_at_tail(Node *head, Node *&tail, int idx) // Complexity O(n)
{
    Node *temp = head;
    for (int i = 1; i < idx; i++)
    {
        temp = temp->next;
    }

    Node *deleteNode = temp->next;
    temp->next = deleteNode->next; // temp->next = NULL; it's also fine here as we are deleting the tail node
    delete deleteNode;
    tail = temp;
}

void delete_at_head(Node *&head) // Complexity O(1)
{
    if (head == NULL)
        return;

    Node *deleteNode = head;
    head = head->next;
    delete deleteNode;
}

void delete_at_position(Node *head, int idx) // Why head is not passed by reference? Because we are not going to change the head pointer here. Complexity O(n)
{
    Node *temp = head;
    for (int i = 1; i < idx; i++)
    {
        temp = temp->next;
    }

    Node *deleteNode = temp->next;
    temp->next = deleteNode->next;
    delete deleteNode;
}

void sort_linked_list(Node *head) // Bubble/Selection Sort. Complexity O(n^2). C++ built-in sort function is not applicable here as it linked list not stored in contiguous memory.
{
    for (Node *i = head; i->next != NULL; i = i->next)
    {
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (i->value > j->value) // Ascending order
            {
                swap(i->value, j->value);
            }
        }
    }
}