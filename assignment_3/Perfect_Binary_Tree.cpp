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

pair<int, int> depth_and_nodes(Node *root)
{
    if (root == NULL)
        return {0, 0};
    pair<int, int> left = depth_and_nodes(root->left);
    pair<int, int> right = depth_and_nodes(root->right);

    int depth = max(left.first, right.first) + 1;
    int nodes = left.second + right.second + 1;
    return {depth, nodes};
}

int main()
{
    Node *root = input_binary_tree();
    pair<int, int> result = depth_and_nodes(root);
    int depth = result.first;
    int nodes = result.second;

    int max_nodes = pow(2, depth) - 1;
    if (nodes == max_nodes)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}