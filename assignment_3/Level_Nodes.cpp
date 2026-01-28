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

int get_tree_level(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 0;
    int left_level = get_tree_level(root->left);
    int right_level = get_tree_level(root->right);
    return max(left_level, right_level) + 1;
}

void print_tree_at_certain_level(Node *root, int level, int curr_level = 0)
{
    if (root == NULL)
        return;

    if (curr_level == level)
    {
        cout << root->value << " ";
        return;
    }
    print_tree_at_certain_level(root->left, level, curr_level + 1);
    print_tree_at_certain_level(root->right, level, curr_level + 1);
}

int main()
{
    Node *root = input_binary_tree();
    int x;
    cin >> x;
    int tree_level = get_tree_level(root);
    if (tree_level < x || x < 0)
    {
        cout << "Invalid" << endl;
    }
    else
    {
        print_tree_at_certain_level(root, x);
        cout << endl;
    }
    return 0;
}