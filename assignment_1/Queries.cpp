#include <bits/stdc++.h>
using namespace std;
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

void print_linked_list(Node *head)
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

    Node *head = NULL;
    Node *tail = NULL;

    int Q;
    cin >> Q;
    while (Q--)
    {
        int X, V;
        cin >> X >> V;
        if (X == 0)
        {
            Node *newNode = new Node(V);
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                newNode->next = head;
                head = newNode;
            }
        }
        else if (X == 1)
        {
            Node *newNode = new Node(V);
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
        else if (X == 2)
        {
            if (head == NULL)
            {
                print_linked_list(head);
                continue;
            }
            if (V == 0)
            {
                Node *deleteNode = head;
                head = head->next;
                if (head == NULL)
                {
                    tail = NULL;
                }
                delete deleteNode;
            }
            else
            {
                Node *temp = head;
                for (int i = 0; i < V - 1 && temp != NULL; i++)
                {
                    temp = temp->next;
                }
                if (temp != NULL && temp->next != NULL)
                {
                    Node *deleteNode = temp->next;
                    temp->next = deleteNode->next;
                    if (deleteNode == tail)
                    {
                        tail = temp;
                    }
                    delete deleteNode;
                }
            }
        }
        print_linked_list(head);
    }

    return 0;
}