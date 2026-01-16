#include <bits/stdc++.h>
using namespace std;

// Implement stack using queue, means turn the queue operations to behave like stack operations
class StackUsingQueue
{
private:
    queue<int> q;

public:
    void push(int data) // stack and queue both push to back O(1)
    {
        q.push(data);
    }
    void pop() // queue pops from front , but stack pops from back O(n)
    {
        queue<int> temp;
        while (q.size() > 1)
        {
            temp.push(q.front());
            q.pop();
        }
        q.pop(); // remove the last element
        q = temp;
    }

    int top() // queue back is stack top O(1)
    {
        if (!q.empty())
        {
            return q.back();
        }
        return -1; // or throw an exception
    }

    int size() // same for both stack and queue O(1)
    {
        return q.size();
    }

    bool empty() // same for both stack and queue O(1)
    {
        return q.empty();
    }
};

// Implement queue using stack, means turn the stack operations to behave like queue operations
class QueueUsingStack
{
private:
    stack<int> s;

public:
    void push(int data) // both stack & queue push to back O(1)
    {
        s.push(data);
    }
    void pop() // stack pops from back , but queue pops from front O(n)
    {
        stack<int> temp;
        while (s.size() > 1)
        {
            temp.push(s.top());
            s.pop();
        }
        s.pop(); // remove the last element
        while (!temp.empty())
        {
            s.push(temp.top());
            temp.pop();
        } // Why can not just do s = temp; ? Because the order will be reversed. If s = [1,2,3], temp = [3,2], so s = temp will make s = [3,2], we want s = [2,3]. So we need to push back the elements from temp to s to maintain the correct order.
    }
    int front() // stack bottom is queue front O(n)
    {
        stack<int> temp;
        int val;
        while (!s.empty()) // move all elements to temp, so the bottom of s becomes top of temp
        {
            temp.push(s.top());
            s.pop();
        }
        if (!temp.empty()) // get the top element of temp which is the bottom of s
        {
            val = temp.top();
        }
        while (!temp.empty()) // push back to original stack
        {
            s.push(temp.top());
            temp.pop();
        }
        return val;
    }
    int back() // stack top is queue back O(1)
    {
        if (!s.empty())
        {
            return s.top();
        }
        return -1; // or throw an exception
    }
    int size() // same for both stack and queue O(1)
    {
        return s.size();
    }
    bool empty() // same for both stack and queue O(1)
    {
        return s.empty();
    }
};

int main()
{
    // Stack using Queue
    StackUsingQueue s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        s.push(val);
    }
    cout << "Top element of stack using queue: " << s.top() << endl;
    s.pop();
    cout << "Top element of stack using queue after pop: " << s.top() << endl;
    cout << "Size of stack using queue: " << s.size() << endl;
    cout << "Is stack using queue empty? " << (s.empty() ? "Yes" : "No") << endl;
    
    // Queue using Stack
    QueueUsingStack q;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        q.push(val);
    }
    cout << "Front element of queue using stack: " << q.front() << endl;
    q.pop();
    cout << "Front element of queue using stack after pop: " << q.front() << endl;
    cout << "Back element of queue using stack: " << q.back() << endl;
    cout << "Size of queue using stack: " << q.size() << endl;
    cout << "Is queue using stack empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}