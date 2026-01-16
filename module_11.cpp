#include <bits/stdc++.h>
using namespace std;

// *Stack: A stack is a linear data structure that follows the Last In First Out (LIFO) principle. Elements can be added or removed only from the top of the stack. It supports two primary operations: push (to add an element on top) and pop (to remove the top element).
// Stack is abstract, higher level data structure that can be implemented using arrays or linked lists.
// When to use Stack?
// 1. To reverse a collection of elements.
// 2. To keep track of function calls (call stack).
// 3. To evaluate expressions (infix, postfix, prefix).
// 4. To implement backtracking algorithms (like maze solving, N-Queens problem).

// Stack Operations:
// 1. push(): Adds an element to the top of the stack. O(1)
// 2. pop(): Removes the top element from the stack. O(1)
// 3. peek()/top(): Returns the top element without removing it. O(1)
// 4. size(): Returns the number of elements in the stack. O(1)
// 5. empty(): Checks if the stack is empty & returns a boolean value. O(1)

// Implementation of Stack using Vectors
class StackUsingVector
{
private:
    vector<int> v;

public:
    void push(int data)
    {
        v.push_back(data);
    }

    void pop()
    {
        if (!v.empty())
        {
            v.pop_back();
        }
    }

    int top()
    {
        if (!v.empty())
        {
            return v.back();
        }
        return -1; // or throw an exception
    }

    int size()
    {
        return v.size();
    }

    bool empty()
    {
        return v.empty();
    }
};

// Implementation of Stack using List, exactly same as vector based stack
class StackUsingList
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
            l.pop_back();
        }
    }
    int top()
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

// Implementation of Stack using Doubly Linked List
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

class StackUsingDLL
{
private:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

public:
    void push(int data)
    {
        sz++;
        Node *newNode = new Node(data);
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
        if (tail == NULL)
        {
            head = NULL;
            return;
        }
        else if (head == tail)
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

int main()
{
    StackUsingList st; // StackUsingVector st; StackUsingDLL st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        st.push(data);
    }
    cout << "Top element: " << st.top() << endl;
    st.pop();
    cout << "Top element after pop: " << st.top() << endl;
    cout << "Stack size: " << st.size() << endl;
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl;

    // To print all elements from the stack, pop elements until the stack is empty. there is no direct way to iterate through stack elements. Stack always prints in reverse order of insertion.
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    // Implementation of Stack using STL
    stack<int> stlStack;
    stlStack.push(1);
    stlStack.push(2);
    cout << "\nTop element of STL stack: " << stlStack.top() << endl;
    stlStack.pop();
    if(!stlStack.empty()) cout << "Top element of STL stack after pop: " << stlStack.top() << endl;
    cout << "Size of STL stack: " << stlStack.size() << endl;
    cout << "Is STL stack empty? " << (stlStack.empty() ? "Yes" : "No") << endl;
    return 0;
}