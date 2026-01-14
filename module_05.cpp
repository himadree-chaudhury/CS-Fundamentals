#include <bits/stdc++.h>
using namespace std;

// Linked List Operations
// Insertion: at head, at tail, at position

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

void insert_at_head(Node *&head, int val);
void insert_at_tail(Node *&head, Node *&tail, int val);
void insert_at_position(Node *&head, int idx, int val);

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *tail = new Node(30);

    head->next = second;
    second->next = tail;

    // Insert at head
    insert_at_head(head, 5);

    // Insert at tail
    insert_at_tail(head, tail, 40);

    // Insert at position
    insert_at_position(head, 2, 15); // Insert 15 at index 2

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    return 0;
}

void insert_at_head(Node *&head, int val) // Pass by reference so that changes reflect outside. Complexity O(1)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insert_at_tail(Node *&head,Node *&tail, int val) // Complexity O(1)
{
    Node *newNode = new Node(val);
    if (head == NULL) // Corner case: when the list is empty
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void insert_at_position(Node *&head, int idx, int val) // Complexity O(n)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    for (int i = 1; i < idx; i++)
    {

        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}