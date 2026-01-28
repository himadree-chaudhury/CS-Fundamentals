#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->value = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input_binary_tree()
{
    int val;
    cin >> val;

    Node *root = NULL;
    if (val != -1)
        root = new Node(val);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        if (l != -1)
        {
            p->left = new Node(l);
            q.push(p->left);
        }
        if (r != -1)
        {
            p->right = new Node(r);
            q.push(p->right);
        }
    }
    return root;
}

void print_outer_most_tree(Node *root)
{
    if (root == NULL)
        return;

    vector<int> left_boundary;
    Node *curr = root->left;
    while (curr)
    {
        left_boundary.push_back(curr->value);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }

    reverse(left_boundary.begin(), left_boundary.end());
    for (int val : left_boundary)
        cout << val << " ";
    cout << root->value << " ";

    vector<int> right_boundary;
    curr = root->right;
    while (curr)
    {
        right_boundary.push_back(curr->value);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }

    for (int i : right_boundary)
        cout << i << " ";
}

int main()
{
    Node *root = input_binary_tree();
    print_outer_most_tree(root);
    return 0;
}