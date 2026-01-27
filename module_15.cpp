#include <bits/stdc++.h>
using namespace std;

// Non linear Data Structures: Non linear data structures are those data structures in which the data elements are not arranged in a sequential manner. Instead, they are arranged in a hierarchical manner or in a way that allows for multiple connections between elements. Examples of non-linear data structures include trees and graphs.

// *Tree
// A tree is a hierarchical data structure that consists of nodes connected by edges. It has the following properties:
// 1. The topmost node is called the root.
// 2. Each node can have zero or more child nodes.
// 3. Nodes with no children are called leaf nodes.
// In tree, only parent to child relationship is there, no sibling or ancestor relationship is present.

// *Binary Tree
// A binary tree is a type of tree data structure in which each node has at most two children, referred to as the left child and the right child. Binary tree can be made from linked list. Properties of binary trees include:
// 1. The maximum number of nodes at level 'l'(leaf-node) is 2^l. e.g., at level 0 (root level), there is 2^0 = 1 node; at level 1, there are 2^1 = 2 nodes; at level 2, there are 2^2 = 4 nodes, and so on.
// 2. The maximum number of nodes in a binary tree of height 'h' is 2^(h+1) - 1. e.g., for a binary tree of height 2, the maximum total number of nodes is 2^(2+1) - 1 = 7.
// 3. In a binary tree with 'n' nodes, the minimum possible height is log2(n + 1) - 1. e.g., for a binary tree with 7 nodes, the minimum height is log2(7 + 1) - 1 = 2.

// N-ary Tree: N-ary tree is a generalization of a binary tree where each node can have at most 'N' children.

// *Traversal Order:
// 1. Depth-wise: In depth-wise traversal, we explore as far down a branch as possible before backtracking. The common depth-wise traversal methods are:
// i. Preorder : In preorder traversal, we visit the root node first, then recursively visit the left subtree, followed by the right subtree.(root -> left-subtree -> right-subtree)
// ii. Inorder: In inorder traversal, we recursively visit the left subtree first, then visit the root node, and finally recursively visit the right subtree.(left-subtree -> root -> right-subtree)
// iii. Postorder: In postorder traversal, we recursively visit the left subtree first, then the right subtree, and finally visit the root node.(left-subtree -> right-subtree -> root)

// 2. Level-wise: In level-wise traversal, we visit all the nodes at the present depth level before moving on to the nodes at the next depth level. The common level-wise traversal method is:
// i. Level order traversal: In level order traversal, we visit the nodes level by level from left to right. This is typically implemented using a queue data structure.

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

void pre_order_traversal(Node *root)
{
    if (root == NULL)
        return;

    cout << root->value << " ";
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);
}

void in_order_traversal(Node *root)
{
    if (root == NULL)
        return;

    in_order_traversal(root->left);
    cout << root->value << " ";
    in_order_traversal(root->right);
}

void post_order_traversal(Node *root)
{
    if (root == NULL)
        return;

    post_order_traversal(root->left);
    post_order_traversal(root->right);
    cout << root->value << " ";
}

int main()
{

    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Preorder Traversal
    cout << "Preorder Traversal: ";
    pre_order_traversal(root);

    // Inorder Traversal
    cout << "\nInorder Traversal: ";
    in_order_traversal(root);

    // Postorder Traversal
    cout << "\nPostorder Traversal: ";
    post_order_traversal(root);

    return 0;
}