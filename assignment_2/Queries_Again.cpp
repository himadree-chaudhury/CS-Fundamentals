#include <bits/stdc++.h>
using namespace std;

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

int get_length(Node *head)
{
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

void insert_at_any_position(Node *&head, Node *&tail, int idx, int val)
{
    if (idx == 0)
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
        return;
    }

    Node *temp = head;
    for (int i = 1; i < idx; i++)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        Node *newNode = new Node(val);
        temp->next = newNode;
        newNode->prev = temp;
        tail = newNode;
        return;
    }

    Node *newNode = new Node(val);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}
void print(Node *head, Node *tail)
{
    Node *temp = head;
    cout << "L -> ";
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;

    temp = tail;
    cout << "R -> ";
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int q;
    cin >> q;
    while (q--)
    {
        int x, val;
        cin >> x >> val;
        if (x > get_length(head))
            cout << "Invalid" << endl;
        else
        {
            insert_at_any_position(head, tail, x, val);
            print(head, tail);
        }
    }
    return 0;
}