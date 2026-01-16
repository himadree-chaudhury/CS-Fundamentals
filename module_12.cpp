#include <bits/stdc++.h>
using namespace std;

// *Quueue: A queue is a linear data structure that follows the First In First Out (FIFO) principle. Elements are added at the rear (enqueue) and removed from the head (dequeue). It supports two primary operations: enqueue (to add an element at the rear) and dequeue (to remove the head element).
// Queue is abstract, higher level data structure that can be implemented using linked lists. For array the time complexity of dequeue operation will be O(n) as elements need to be shifted front, so linked list is preferred.

// Queue Operations:
// 1. push()/enqueue(): Adds an element to the rear of the queue. O(1)
// 2. pop()/dequeue(): Removes the head element from the queue. O(1)
// 3. head(): Returns the head element without removing it. O(1)
// 4. back(): Returns the rear element without removing it. O(1)
// 5. size(): Returns the number of elements in the queue. O(1)
// 6. empty(): Checks if the queue is empty & returns a boolean value. O(1)

// Implementation of Queue using Singly Linked List
class NodeSSL
{
public:
    int value;
    NodeSSL *next;
    NodeSSL(int val)
    {
        this->value = val;
        this->next = NULL;
    }
};

class QueueUsingSLL
{
private:
    NodeSSL *head = NULL;
    NodeSSL *tail = NULL;
    int sz = 0;

public:
    void push(int data)
    {
        sz++;
        NodeSSL *newNodeSSL = new NodeSSL(data);
        if (head == NULL)
        {
            head = newNodeSSL;
            tail = newNodeSSL;
        }
        else
        {
            tail->next = newNodeSSL;
            tail = newNodeSSL;
        }
    }
    void pop()
    {
        sz--;
        if (head == NULL)
        {
            tail == NULL;
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            NodeSSL *deleteNodeSSL = head;
            head = head->next;
            delete deleteNodeSSL;
        }
    }
    int front()
    {
        if (head != NULL)
        {
            return head->value;
        }
        return -1; // or throw an exception
    }
    int back()
    {
        if (tail != NULL)
        {
            return tail->value;
        }
        return -1; // or throw an exception
    }
    int size()
    {
        return sz;
    }
    bool empty()
    {
        return sz == 0; // or return head == NULL;
    }
};

// Implementation of Queue using Doubly Linked List
class NodeDLL
{
public:
    int value;
    NodeDLL *prev;
    NodeDLL *next;

    NodeDLL(int val)
    {
        this->value = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

class QueueUsingDLL
{
private:
    NodeDLL *head = NULL;
    NodeDLL *tail = NULL;
    int sz = 0;

public:
    void push(int data)
    {
        sz++;
        NodeDLL *newNode = new NodeDLL(data);
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
        sz--;
        if (head == NULL)
        {
            tail == NULL;
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            NodeDLL *deleteNode = head;
            head = head->next;
            head->prev = NULL;
            delete deleteNode;
        }
    }
    int front()
    {
        if (head != NULL)
        {
            return head->value;
        }
        return -1; // or throw an exception
    }
    int back()
    {
        if (tail != NULL)
        {
            return tail->value;
        }
        return -1; // or throw an exception
    }
    int size()
    {
        return sz;
    }
    bool empty()
    {
        return sz == 0; // or return head == NULL;
    }
};

// Implementation of Queue using List
class QueueUsingList
{
private:
    list<int> l;

public:
    void push(int data)
    {
        l.push_back(data);
    }
    void pop()
    {
        if (!l.empty())
        {
            l.pop_front();
        }
    }
    int front()
    {
        if (!l.empty())
        {
            return l.front();
        }
        return -1; // or throw an exception
    }
    int back()
    {
        if (!l.empty())
        {
            return l.back();
        }
        return -1; // or throw an exception
    }
    int size()
    {
        return l.size();
    }
    bool empty()
    {
        return l.empty();
    }
};

int main()
{

    QueueUsingList q; // QueueUsingSLL q; QueueUsingDLL q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        q.push(val);
    }
    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;
    cout << "Queue size: " << q.size() << endl;
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    // Implementation of Queue using STL
    queue<int> stlQueue;
    stlQueue.push(1);
    stlQueue.push(2);
    cout << "\nFront element of STL queue: " << stlQueue.front() << endl;
    stlQueue.pop();
    if (!stlQueue.empty())
        cout << "Front element of STL queue after pop: " << stlQueue.front() << endl;
    if (!stlQueue.empty())
        cout << "Back element of STL queue: " << stlQueue.back() << endl;
    cout << "Size of STL queue: " << stlQueue.size() << endl;
    cout << "Is STL queue empty? " << (stlQueue.empty() ? "Yes" : "No") << endl;
    return 0;
}