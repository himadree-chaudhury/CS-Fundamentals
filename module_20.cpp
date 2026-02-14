#include<bits/stdc++.h>
using namespace std;

// Complete Binary Tree: A complete binary tree is a binary tree in which all levels are completely filled except possibly the last level, and the last level has all keys as left as possible. It can be represented using an array where for any given index i of the array:
    // If the index of the current node is i and it is a parent node, then
    // The left child is at index 2*i + 1
    // The right child is at index 2*i + 2
    // If the index of the current node is i and it is a child node, then
    // The parent is at index (i-1)/2
// The height of a complete binary tree with n nodes is log2(n) (rounded down).

// Perfect Binary Tree: A perfect binary tree is a binary tree in which all interior nodes have two children and all leaves are at the same level. The number of nodes in a perfect binary tree of height h is 2^(h+1) - 1.

// *Heap: A heap is a specialized tree-based data structure that satisfies the heap property(). In a max heap, for any given node I, the value of I is greater than or equal to the values of its children, and in a min heap, for any given node I, the value of I is less than or equal to the values of its children. Heaps are commonly used to implement priority queues and for efficient sorting algorithms like heapsort.

// Heap uses complete binary tree as its underlying data structure . The height of a heap with n nodes is log2(n) (rounded down). Heap maintains an array representation(level order) of the complete binary tree, where the parent-child relationships are maintained according to the heap property.



int main(){
    // Insert a value in heap:
    // 1. Heap uses complete binary tree as its underlying data structure, so we insert the new value at the end of the tree or a position which satisfy complete binary tree property (the next available position in the array representation).
    // 2. After inserting the new value, we need to maintain the heap property. In max heap, we compare the inserted value with its parent node and if the inserted value is greater than its parent, we swap them. We repeat this process until the heap property is satisfied or we reach the root of the tree. In min heap, we compare the inserted value with its parent node and if the inserted value is less than its parent, we swap them. We repeat this process until the heap property is satisfied or we reach the root of the tree.
    vector<int> heap = {10, 9, 8, 7, 6}; // This is a max heap
    int new_value = 11;
    
    // Insert new value at the end of the heap
    heap.push_back(new_value);
    
    // Maintain heap property (max heap)
    int index = heap.size() - 1;
    int parent_index = (index - 1) / 2;
    while(index > 0 && heap[index] > heap[parent_index]){
        // for min heap, change the condition to heap[index] < heap[parent_index]
        swap(heap[index], heap[parent_index]);
        index = parent_index;
        parent_index = (index - 1) / 2;
    }
    // Time Complexity: O(h) or O(log n), where h is the height of the heap and n is the number of nodes in the heap. This is for single insertion. So, for inserting n nodes, it is O(n * log n).
    
    // Print the updated heap
    cout << "Updated Heap After Inserting: ";
    for(int i = 0; i < heap.size(); i++){
        cout << heap[i] << " ";
    }
    cout << endl;

    // Delete a value from heap:
    // 1. In a heap, we typically delete the root node (the maximum element in a max heap or the minimum element in a min heap). To delete the root node, we replace it with the last element in the heap (the last element in the array representation) and then remove the last element from the heap.
    // 2. After replacing the root node with the last element, we need to maintain the heap property. In a max heap, we compare the new root node with its children and if it is smaller than any of its children, we swap it with the larger child. We repeat this process until the heap property is satisfied or we reach a leaf node. In a min heap, we compare the new root node with its children and if it is greater than any of its children, we swap it with the smaller child. We repeat this process until the heap property is satisfied or we reach a leaf node.
    
    // Delete root node (max heap)
    int root = heap[0];
    heap[0] = heap[heap.size() - 1];    // Can be done with heap.back() as well
    heap.pop_back();
    
    // Maintain heap property (max heap)
    int current_index = 0;
    while(current_index < heap.size()){
        int left_child_index = 2 * current_index + 1;
        int right_child_index = 2 * current_index + 2;
        int max_child_index = current_index;
        
        if(left_child_index < heap.size() && heap[left_child_index] > heap[max_child_index]){
            max_child_index = left_child_index;
        }
        if(right_child_index < heap.size() && heap[right_child_index] > heap[max_child_index]){
            max_child_index = right_child_index;
        }
        
        if(max_child_index == current_index){
            break;
        }
        
        swap(heap[current_index], heap[max_child_index]);
        current_index = max_child_index;

        // For min heap, change the conditions to heap[left_child_index] < heap[min_child_index] and heap[right_child_index] < heap[min_child_index]

        // Time Complexity: O(h) or O(log n), where h is the height of the heap and n is the number of nodes in the heap. This is for single deletion. So, for deleting n nodes, it is O(n * log n).
    }
    
    cout << "Deleted Root Node: " << root << endl;
    cout << "Updated Heap After Deletion: ";
    for(int i = 0; i < heap.size(); i++){
        cout << heap[i] << " ";
    }
    cout << endl;

    return 0;
}