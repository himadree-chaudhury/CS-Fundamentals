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

class Stack
{
private:
    Node *head = NULL;
    Node *tail = NULL;

public:
    void push(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop()
    {
        if (tail == NULL)
        {
            head = NULL;
            return;
        }
        if (head == tail)
        {
            delete tail;
            head = NULL;
            tail = NULL;
        }
        else
        {
            Node *deleteNode = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete deleteNode;
        }
    }
    int top()
    {
        return tail->value;
    }
    bool empty()
    {
        return head == NULL;
    }
};

class Queue
{
private:
    Node *head = NULL;
    Node *tail = NULL;

public:
    void push(int val)
    {
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
    void pop()
    {
        if (head == NULL)
        {
            tail = NULL;
            return;
        }
        if (head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            Node *deleteNode = head;
            head = head->next;
            head->prev = NULL;
            delete deleteNode;
        }
    }
    int front()
    {
        return head->value;
    }
    bool empty()
    {
        return head == NULL;
    }
};

int main()
{
    Stack s;
    Queue q;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    vector<int> v1, v2;
    while (!s.empty())
    {
        v1.push_back(s.top());
        s.pop();
    }
    while (!q.empty())
    {
        v2.push_back(q.front());
        q.pop();
    }
    v1 == v2 ? cout << "YES" << endl : cout << "NO" << endl;
    return 0;
}