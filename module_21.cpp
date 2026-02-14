#include <bits/stdc++.h>
using namespace std;

// *Priority Queue: A priority queue is an abstract data type that operates similar to a regular queue but with an added feature of priority. In a priority queue, each element is associated with a priority, and elements are served based on their priority. The element with the highest/lowest priority is served first. If two elements have the same priority, they are served according to their order in the queue (first come, first served).
// Priority queues can be implemented using various data structures, including heaps, linked lists, or arrays. Heaps are commonly used for efficient implementation of priority queues due to their ability to maintain the heap property and provide efficient insertion and deletion operations.
// priority_queue<type> pq; // Max priority queue by default
// priority_queue<type, vector<type>, greater<type>> pq; // Min priority

// Array vs Priority Queue:
// 1. To find the max or min element in an array, we need to sort the array first, which takes O(n log n) time. In a priority queue implemented using a heap, we can find the max or min element in O(1) time.
// 2. Inserting an element in an array takes O(1) time if we insert at the end, but if we want to maintain a sorted order, it takes O(n) time. In a priority queue implemented using a heap, inserting an element takes O(log n) time.
// 3. Deleting the max or min element from an array takes O(n) time if we want to maintain a sorted order, but if we don't care about the order, it takes O(1) time. In a priority queue implemented using a heap, deleting the max or min element takes O(log n) time.

// Custom class for priority queue
class CustomCompare
{
public:
    // This function has to be named operator() for all comparison classes used in priority_queue
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        // Compare based on the second element of the pair (priority)
        return a.second > b.second; // For min priority queue
        // return a.second < b.second; // For max priority queue

        // Normally a < b gives the ascending order. But the priority_queue doesn't ask "which comes first?" it asks "does 'a' have lower priority than 'b'?" If the comparison returns true, the priority queue thinks a is "less than" b in terms of importance. In a heap structure, the elements with the least importance are pushed to the bottom. Therefore, if operator() returns true, a is moved deeper into the tree. So, in max heap if a is smaller, put it lower, in min-heap if a is larger, put it lower.
    }
};

// Limitation o Frequency array:
// 1. Only count intergers, no floating point numbers or negative numbers allowed, as the index of the array represents the number itself.
// 2. Index ranging from 0 to maximum 10^6, with no negative numbers allowed, meaning can count upto 10^6 different numbers.
// 3. Memory inefficient if the range of numbers is large but the actual count of numbers is small, as it allocates memory for all possible numbers in the range, even if many of them are not present in the input data. Like for an array[10005, 1000000], we are allocating memory for 999995 numbers, which is a huge waste of memory if we only have a few numbers in that range.

// To overcome these limitations, we can use a map
// *Map: A map is a data structure that stores key-value pairs, where each key is unique and maps to a specific value.
// Maps can store any type of data as keys and values, including integers, floating-point numbers, strings, and even custom objects. Store only the numbers that are present in the input data, and we can easily retrieve the count of any number by using its value as the key in the map. Store upto 10^18 different numbers.
// map<key_type, value_type> map_name;

// *Set: A set is a data structure that stores unique elements in a sorted manner. It does not allow duplicate values and automatically sorts the elements in ascending order. Sets utilizes balanced BST internally. Balanced BST is a binary search tree that maintains its height to be logarithmic with respect to the number of nodes menas height of the tree is O(log n).
// set<element_type> set_name;

int main()
{
    // Priority queue operations:
    priority_queue<int> max_pq;                            // Max priority queue
    priority_queue<int, vector<int>, greater<int>> min_pq; // Min priority queue, vector<int> is the underlying container and greater<int> is the comparison function to maintain min heap property

    // Inserting elements into max priority queue
    max_pq.push(10);
    max_pq.push(20);
    max_pq.push(5);

    // Printing the top element of max priority queue
    cout << "Top element of max priority queue: " << max_pq.top() << endl;

    // Size of max priority queue
    cout << "Size of max priority queue: " << max_pq.size() << endl;

    // Check empty or not
    cout << "Is max priority queue empty? " << (max_pq.empty() ? "Yes" : "No") << endl;

    // Removing the top element from max priority queue
    max_pq.pop();

    // Printing the new top element of max priority queue
    cout << "New top element of max priority queue after popping: " << max_pq.top() << endl;

    // Inserting elements into min priority queue
    min_pq.push(10);
    min_pq.push(20);
    min_pq.push(5);

    // Printing the top element of min priority queue
    cout << "Top element of min priority queue: " << min_pq.top() << endl;

    // Removing the top element from min priority queue
    min_pq.pop();

    // Printing the new top element of min priority queue
    cout << "New top element of min priority queue after popping: " << min_pq.top() << endl;

    // Priority queue can take custom compare class as well. For example, we can create a priority queue of pairs where the first element of the pair is the value and the second element is the priority. We can then define a custom comparison function to maintain the order based on the priority.
    priority_queue<pair<int, int>, vector<pair<int, int>>, CustomCompare> custom_pq; // Min priority queue based on the second element of the pair (priority)
    custom_pq.push({1, 3});                                                          // value = 1, priority = 3
    custom_pq.push({2, 1});                                                          // value = 2, priority = 1
    custom_pq.push({3, 2});                                                          // value = 3, priority = 2

    // Printing the top element of custom priority queue
    cout << "Top element of custom priority queue (value, priority): (" << custom_pq.top().first << ", " << custom_pq.top().second << ")" << endl;

    // Map operations:
    map<int, int> frequency_map; // Map to store the frequency of numbers

    // Inserting elements into the map
    frequency_map[10]++; // O(log n)
    frequency_map[20]++;
    frequency_map[10]++; // Incrementing the count of 10

    // Printing the frequency of a number
    for (auto it = frequency_map.begin(); it != frequency_map.end(); it++)
    {
        cout << "Number: " << it->first << ", Frequency: " << it->second << endl; // O(log n) for each access
    }

    // Count of a specific number
    if (frequency_map.count(10))
    { // O(log n)
        cout << "Frequency of 10: " << frequency_map[10] << endl;
    }
    else
    {
        cout << "10 is not present in the map." << endl;
    }

    // Count words in a string using map
    string s;
    getline(cin, s);
    stringstream ss(s);
    map<string, int> word_count;
    string word;
    while (ss >> word)
    {
        word_count[word]++;
    }

    cout << "Word frequencies:" << endl;
    for (auto it = word_count.begin(); it != word_count.end(); it++)
    {
        cout << "Word: " << it->first << ", Frequency: " << it->second << endl;
    }

    // Set operations:
    set<int> unique_numbers; // Set to store unique numbers

    // Inserting elements into the set
    unique_numbers.insert(10); // O(log n)
    unique_numbers.insert(20);
    unique_numbers.insert(10); // Duplicate, will not be inserted

    // Printing the unique numbers in the set
    cout << "Unique numbers in the set: ";
    for (auto it = unique_numbers.begin(); it != unique_numbers.end(); it++)
    {
        cout << *it << " "; // O(log n) for each access
    }

    // Check if a number is present in the set
    if (unique_numbers.count(10))
    { // O(log n)
        cout << "\n10 is present in the set." << endl;
    }
    else
    {
        cout << "\n10 is not present in the set." << endl;
    }

    // Set can not be reversed, but we can use reverse iterators to traverse the set in reverse order
    cout << "Unique numbers in the set in reverse order: ";
    for (auto it = unique_numbers.rbegin(); it != unique_numbers.rend(); it++)
    {
        cout << *it << " "; // O(log n) for each access
    } // why not it=unique_numbers.end() -1; it!=unique_numbers.begin; it--? because set is implemented as a balanced BST, and it does not support random access iterators, so we cannot use it like an array. We have to use reverse iterators to traverse the set in reverse order.
    return 0;
}