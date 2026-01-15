#include <bits/stdc++.h>
using namespace std;

//*Doubly Linked List: DLL is a type of linked list in which each node contains a data part and two pointers. One pointer points to the next node in the sequence and the other pointer points to the previous node in the sequence. This allows traversal of the list in both directions, forward and backward.

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

void print_backward(Node *tail)
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->prev;
    }
    cout << endl;
}

void insert_at_head(Node *&head, Node *&tail, int val) // Complexity: O(1)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insert_at_tail(Node *&head, Node *&tail, int val) // Complexity: O(1)
{
    Node *newNode = new Node(val);
    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insert_at_position(Node *&head, int idx, int val) // Complexity: O(n)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    for (int i = 1; i < idx; i++) // idx is expected to be 0 base index, so we run the loop from 1 to idx-1 to reach the node just before the desired position
    {
        temp = temp->next;
    }
    newNode->next = temp->next; // Linking new node to the next node
    temp->next->prev = newNode; // Linking next node back to the new node
    temp->next = newNode;       // Linking current node to the new node
    newNode->prev = temp;       // Linking new node back to the current node

    // Assume a list: A<=>B<=>C, and we want to insert X at position 1 (after A), goal is A<=>X<=>B<=>C
    // Step 1: newNode->next = temp->next; // X->next = B
    // Step 2: temp->next->prev = newNode; // B->prev = X
    // Step 3: temp->next = newNode;       // A->next = X
    // Step 4: newNode->prev = temp;       // X->prev = A
}

void delete_at_head(Node *&head, Node *&tail) // Complexity: O(1)
{
    if (head == NULL)
    {
        return;
    }
    Node *deleteNode = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL; // The previous pointer of the new head should be NULL
    }
    else
    {
        tail = NULL; // When there was only one node, deleteling it makes both head and tail NULL; head is already updated to NULL at head = head->next as there will be no next node.
    }
    delete deleteNode;
}

void delete_at_tail(Node *&head, Node *&tail) // Complexity: O(1)
{
    if (tail == NULL)
    {
        return;
    }
    Node *deleteNode = tail;
    tail = tail->prev;
    if (tail != NULL)
    {
        tail->next = NULL; // The next pointer of the new tail should be NULL
    }
    else
    {
        head = NULL; // When there was only one node, deleteling it makes both head and tail NULL; tail is already updated to NULL at tail = tail->prev as there will be no previous node.
    }
    delete deleteNode;
}

void delete_at_position(Node *&head, Node *&tail, int idx) // Complexity: O(n)
{
    Node *temp = head;
    for (int i = 1; i < idx; i++) // idx is expected to be 0 base index, so we run the loop from 1 to idx-1 to reach the node just before the desired position
    {
        temp = temp->next;
    }
    Node *deleteNode = temp->next;
    temp->next = deleteNode->next; // Bypass the deleteNode
    deleteNode->next->prev = temp; // Link back the previous pointer of the next node
    delete deleteNode;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        insert_at_tail(head, tail, val);
    }

    insert_at_head(head, tail, 100);
    insert_at_tail(head, tail, 200);
    insert_at_position(head, 2, 150); // Inserting 150 at index 2
    delete_at_head(head, tail);
    delete_at_tail(head, tail);
    delete_at_position(head, tail, 2); // Deleting node at index 2

    cout << "DLL forward: ";
    print_forward(head);
    cout << "DLL backward: ";
    print_backward(tail);

    return 0;
}