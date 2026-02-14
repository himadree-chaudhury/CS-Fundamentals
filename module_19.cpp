#include <bits/stdc++.h>
using namespace std;

// *Binary Search Tree (BST): A binary search tree is a binary tree in which each node has a value, and the value of each node is greater than the values of all nodes in its left subtree and less than the values of all nodes in its right subtree. No value should be repeated in a BST. This property allows for efficient searching, insertion, and deletion operations.
// BST = Binary Tree + Binary Search
// BST gives a sorted order of elements when we perform an in-order traversal (left, root, right). This is because the left subtree contains values less than the root, and the right subtree contains values greater than the root.

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

Node *insert_into_BST()
{
    int value;
    cin >> value;
    Node *root;
    if (value == -1)
        root = NULL;
    else
        root = new Node(value);

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int left_value, right_value;
        cin >> left_value >> right_value;

        if (left_value != -1)
        {
            temp->left = new Node(left_value);
            q.push(temp->left);
        }
        if (right_value != -1)
        {
            temp->right = new Node(right_value);
            q.push(temp->right);
        }
    }
    return root;
}

bool search_in_BST(Node *root, int key)
{
    if (root == NULL)
        return false;
    if (root->value == key)
        return true;
    else if (key < root->value)
        return search_in_BST(root->left, key);
    else
        return search_in_BST(root->right, key);

    // Time Complexity: O(h), where h is the height of the BST. In the worst case (when the BST is skewed), this can be O(n), where n is the number of nodes in the BST. In the best case (when the BST is balanced means all nodes has left and right children), this can be O(log n).
}

void insert_node(Node *&root, int value)
{
    if (root == NULL)
    {
        root = new Node(value); // Here root node is changing, so we have to pass root by reference in the function parameter
        return;
    }
    if (value < root->value)
        insert_node(root->left, value);
    else
        insert_node(root->right, value);

    // Time Complexity: O(h), where h is the height of the BST for single insertion. So, for inserting n nodes, it is O(n * h). In the worst case (when the BST is skewed), this can be O(n^2), where n is the number of nodes in the BST. In the best case (when the BST is balanced means all nodes has left and right children), this can be O(n * log n).
}

void level_order_traversal(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->value << " ";
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}

Node *array_to_BST(vector<int> &arr, int start_idx, int end_idx)
{

    // The idea is to find the middle element of the array and make it the root of the BST. Then, recursively do the same for the left half and right half of the array to construct the left and right subtrees respectively.

    if (start_idx > end_idx)
        return NULL;
    int mid = (start_idx + end_idx) / 2;
    Node *root = new Node(arr[mid]);
    root->left = array_to_BST(arr, start_idx, mid - 1);
    root->right = array_to_BST(arr, mid + 1, end_idx);
    return root;

    // Time Complexity: O(n), where n is the number of elements in the array. This is because we are creating a node for each element in the array and performing a constant amount of work for each node.
}

int main()
{

    Node *root = insert_into_BST();
    int key;
    cin >> key;

    // Searching in BST

    if (search_in_BST(root, key))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    // Inserting a node in BST
    insert_node(root, 5);

    cout << "Level Order Traversal After Inserting 5: ";
    level_order_traversal(root);

    // Constructing a BST from a sorted array
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node *new_root = array_to_BST(arr, 0, arr.size() - 1);
    cout << "\nLevel Order Traversal of BST Constructed from Sorted Array: ";
    level_order_traversal(new_root);

    return 0;
}