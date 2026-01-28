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

vector<int> get_leaf_nodes(Node *root)
{
    vector<int> leaf_node;
    if (root == NULL)
        return leaf_node;
    if (root->left == NULL && root->right == NULL)
    {
        leaf_node.push_back(root->value);
        return leaf_node;
    }
    vector<int> left_leaves = get_leaf_nodes(root->left);
    vector<int> right_leaves = get_leaf_nodes(root->right);
    leaf_node.insert(leaf_node.end(), left_leaves.begin(), left_leaves.end());
    leaf_node.insert(leaf_node.end(), right_leaves.begin(), right_leaves.end());
    return leaf_node;
}

int main()
{
    Node *root = input_binary_tree();
    vector<int> leaf_nodes = get_leaf_nodes(root);
    sort(leaf_nodes.begin(), leaf_nodes.end(), greater<int>());
    for (int val : leaf_nodes)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}