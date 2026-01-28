#include <bits/stdc++.h>
using namespace std;

// Level order traversal: In level order traversal, we visit the nodes level(from top to bottom) by level from left to right. This is typically implemented using a queue data structure.

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

void level_order_traversal(Node *root)
{
    if (root == NULL)
        return;

    // 1. Initialize an empty queue and enqueue the root node.
    queue<Node *> q;
    q.push(root);

    // 2. While the queue is not empty, repeat the following steps:
    while (!q.empty())
    {
        //    a. Dequeue a node from the front of the queue and process it (e.g., print its value).
        Node *current = q.front();
        q.pop();
        cout << current->value << " ";

        //   b. If the dequeued node has a left child, enqueue the left child.
        if (current->left)
        {
            q.push(current->left);
        }

        //   c. If the dequeued node has a right child, enqueue the right child.
        if (current->right)
        {
            q.push(current->right);
        }
    }
    // 3. Continue this process until the queue is empty, indicating that all nodes have been visited.
}

// Take input a binary tree. Normally queue is used to take input as level order. User input -1 for NULL node. Stpes are:

Node *input_binary_tree()
{
    int val;
    cin >> val;
    if (val == -1)
        return NULL;

    // 1. Initialize an empty queue and enqueue the root node.
    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);

    // 2. While the queue is not empty, repeat the following steps:
    while (!q.empty())
    {
        //     a. Dequeue a node from the front of the queue and process it (e.g., input its children).
        Node *current = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal >> rightVal;

        //     b. If the dequeued node has a left child, enqueue the left child.
        if (leftVal != -1)
        {
            current->left = new Node(leftVal);
            q.push(current->left);
        }

        //     c. If the dequeued node has a right child, enqueue the right child.
        if (rightVal != -1)
        {
            current->right = new Node(rightVal);
            q.push(current->right);
        }
    }
    // 3. Continue this process until the queue is empty, indicating that all nodes have been visited.

    // Finally return the root of the tree
    return root;
}

// Counting all nodes in a binary tree using level order traversal can be done by maintaining a counter that increments each time a node is processed during the traversal. Or use recursion.
int count_nodes(Node *root)
{
    if (root == NULL)
        return 0;

    int left_count = count_nodes(root->left);
    int right_count = count_nodes(root->right);
    return left_count + right_count + 1;      // +1 for the current node
}

// Counting all leaf nodes in a binary tree using level order traversal can be done by maintaining a counter that increments each time a leaf node (a node with no children) is processed during the traversal. Or use recursion.
int count_leaf_nodes(Node *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    int left_leaf_count = count_leaf_nodes(root->left);
    int right_leaf_count = count_leaf_nodes(root->right);
    return left_leaf_count + right_leaf_count;
}

// Height of binary tree: Height of a binary tree is defined as the number of edges on the longest path from the root node to a leaf node. Height count starting from leaf node as 0, then move upwards to root. Whenever moving from a node to its parent, increment the height by 1 and if two children have different heights, take the maximum height.
int height_of_binary_tree(Node *root)
{
    if (root == NULL)
        return 0; // Return -1 for height of empty tree

    if (root->left == NULL && root->right == NULL)
        return 0; // Height of leaf node is 0

    int left_height = height_of_binary_tree(root->left);
    int right_height = height_of_binary_tree(root->right);

    return max(left_height, right_height) + 1; // +1 for the current edge
}

// Depth of binary tree: Depth of a binary tree is defined as the number of edges from the root node to a specific node. Depth count starting from root node as 0, then move downwards to leaf nodes. Whenever moving from a node to its child, increment the depth by 1.
int depth_of_binary_tree(Node *root, int target_value, int current_depth = 0)
{
    if (root == NULL)
        return -1; // Target value not found

    if (root->value == target_value)
        return current_depth;

    int left_depth = depth_of_binary_tree(root->left, target_value, current_depth + 1);     // current_depth + 1 while moving down
    if (left_depth != -1)
        return left_depth;      // Target found in left subtree

    return depth_of_binary_tree(root->right, target_value, current_depth + 1);
}
int main()
{
    Node *root = input_binary_tree();

    // Level Order Traversal
    cout << "Level Order Traversal: ";
    level_order_traversal(root);
    cout << endl;

    // Count Nodes
    int total_nodes = count_nodes(root);
    cout << "Total number of nodes in the binary tree: " << total_nodes << endl;

    // Count Leaf Nodes
    int total_leaf_nodes = count_leaf_nodes(root);
    cout << "Total number of leaf nodes in the binary tree: " << total_leaf_nodes << endl;

    // Height of Binary Tree
    int height = height_of_binary_tree(root);
    cout << "Height of the binary tree: " << height << endl;

    // Depth of Binary Tree (example for value 5)
    int target_value = 5;
    int depth = depth_of_binary_tree(root, target_value);
    if (depth != -1)
        cout << "Depth of node with value " << target_value << ": " << depth << endl;
    else
        cout << "Node with value " << target_value << " not found in the tree." << endl;

    return 0;
}