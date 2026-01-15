#include <bits/stdc++.h>
using namespace std;

// *Detect Cycle in a Linked List: Cycle means a loop in the linked list where a node's next pointer points to a previous node, creating a cycle, like A<=>B<=>C<=>A. Cycle detection in a linked list is a common problem that can be solved using Floyd's Cycle-Finding Algorithm (also known as the Tortoise and Hare algorithm). The idea is to use two pointers that move at different speeds through the linked list. If there is a cycle, the fast & slow pointer will eventually meet the slow pointer. If there is no cycle, the only fast pointer will reach the end of the list.

// The fast pointer moves two steps at a time, while the slow pointer moves one step at a time. If there is a cycle, the fast pointer will eventually meet the slow pointer at any point. If there is no cycle, the fast pointer will reach the end of the list (NULL).

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
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *forth = new Node(30);
    Node *fifth = new Node(30);

    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = second; // Creating a cycle. A->B->C->D->E->B->...

    // Taking two pointers(fast and slow)
    Node *fast = head;
    Node *slow = head;

    bool cycle_found = false;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;       // Move slow pointer by 1 step
        fast = fast->next->next; // Move fast pointer by 2 steps

        if (slow == fast)
        { // Cycle detected. If this condition checks before the slow/fast movement, the loop will break immediately as both pointers are at head initially.
            cycle_found = true;
            break; // If break is not used here, it will be an infinite loop as both pointers are already inside the cycle.
        }
    }
    
    if (cycle_found)
        cout << "Cycle Found" << endl;
    else
        cout << "No Cycle Found" << endl;
    return 0;
}