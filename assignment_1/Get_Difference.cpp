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
    int maxValue = INT_MIN;
    int minValue = INT_MAX;
    for (Node *i = head; i != NULL; i = i->next)
    {
        if (i->value > maxValue)
        {
            maxValue = i->value;
        }
        if (i->value < minValue)
        {
            minValue = i->value;
        }
    }
    cout << maxValue - minValue << endl;

    return 0;
}