#include <bits/stdc++.h>
using namespace std;

// *STL - Standard Template Library
// STL is a powerful set of C++ template classes to provide general-purpose classes and functions with templates. It includes algorithms and data structures that allow programmers to use them without having to implement them from scratch.
// STL builds on Containers, Algorithms, and Iterators. Containers are used to store data like vector, lists, queues, stacks, etc. Algorithms are used to perform operations on these containers like sorting, searching, find etc. Iterators are pointers used to traverse through the elements of the containers.

int main()
{
    // Fast I/O: Using fast input/output operation
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // *Pair
    // A pair is a simple container defined in the <utility> header that holds two values of possibly different types. It is often used to store a pair of related data, such as a key-value pair or a coordinate point.

    pair<string, int> p1 = make_pair("James", 10); // also can be written as pair<string,int> p1("Hello", 10);
    auto [name, score] = p1;                       // structured binding to unpack the pair into separate variables

    cout << "Name: " << name << ", Score: " << score << endl;

    pair<string, int> students[3];
    for (int i = 0; i < 3; i++)
        cin >> students[i].first >> students[i].second;

    for (auto [name, score] : students)
        cout << "Name: " << name << ", Score: " << score << endl;

    // pairs can also be nested
    pair<string, pair<int, double>> p2 = {"Bob", {30, 75.5}};
    cout << "Name: " << p2.first << ", Age: " << p2.second.first << ", Score: " << p2.second.second << endl;

    // *Tuple
    // A tuple is a fixed-size collection of heterogeneous values. It is defined in the <tuple> header and can hold values of different types. Tuples are often used to return multiple values from a function or to group related data together.

    tuple<string, int, double> t1 = make_tuple("Alice", 25, 85.2); // also can be written as tuple<string,int,double> t1=("Alice", 25, 3.14);

    auto [name2, age, score2] = t1;
    cout << "Name: " << name2 << ", Age: " << age << ", Score: " << score2 << endl; // also can be written as cout << "Name: " << get<0>(t1) << ", Age: " << get<1>(t1) << ", Score: " << get<2>(t1) << endl;

    // *Vector
    // A vector is a dynamic array that can resize itself automatically when elements are added or removed. It is defined in the <vector> header and provides random access to its elements. Vectors are commonly used for storing and manipulating collections of data.

    vector<int> v(5, 0); // creates a vector of size 5 initialized with 0
    for (int i = 0; i < v.size(); i++)
        cin >> v[i];

    for (auto it = v.begin(); it != v.end(); it++) // using iterators to traverse the vector
        cout << *it << " ";                        // as iterators are pointers, we need to dereference them to get the value
    cout << endl;

    // rbegin() and rend() are reverse iterators that allow us to traverse the vector in reverse order
    for (auto it = v.rbegin(); it != v.rend(); it++)
        cout << *it << " ";

    auto max_it = max_element(v.begin(), v.end()); // returns an iterator pointing to the maximum element in the vector
    cout << "\nMax element: " << *max_it << endl;
    cout << "Index of max element: " << max_it - v.begin() << endl; // to get the index of the maximum element, we can subtract the beginning iterator from the max iterator

    // 2D vector
    vector<vector<int>> matrix(3, vector<int>(4, 5)); // creates a 3x4 matrix initialized with 0
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[i].size(); j++)
            cin >> matrix[i][j];

    for (const auto row : matrix)
    {
        for (const auto value : row)
            cout << value << " ";
        cout << endl;
    }

    // *Deque
    // A deque (double-ended queue) is a dynamic array that allows fast insertion and deletion at both ends. It is defined in the <deque> header and provides random access to its elements. Deques are often used when we need to add or remove elements from both ends of a collection.\

    deque<int> dq;
    for (int i = 0; i < 5; i++)
        dq.push_back(i);

    dq.push_front(-1); // adding an element at the front
    dq.push_back(5);   // adding an element at the back
    dq.pop_front();    // removing an element from the front
    dq.pop_back();     // removing an element from the back
    for (auto value : dq)
        cout << value << " ";

    // front() and back() functions are used to access the first and last elements of the deque respectively
    cout << "\nFront element: " << dq.front() << endl;
    cout << "Back element: " << dq.back() << endl;

    // Why use vector over deque?: Vector use less momory

    // *String
    // A string is a sequence of characters that represents text. It is defined in the <string> header and provides various functions for manipulating and working with strings. Strings are commonly used for storing and processing textual data.

    // *Map
    // A map is a collection of key-value pairs where each key is unique. It is defined in the <map> header and provides fast retrieval of values based on their corresponding keys. Maps are often used for storing and accessing data based on unique identifiers.

    map<string, int> ageMap;
    ageMap["Alice"] = 25; // also can be written as ageMap.insert({"Alice", 25});
    ageMap["Bob"] = 30;

    for (auto [name, age] : ageMap)
        cout << "Name: " << name << ", Age: " << age << endl;

    auto it = ageMap.find("Alice"); // returns an iterator to the element with key "Alice"
    if (it != ageMap.end())
        cout << "Alice's age: " << it->second << endl; // as the iterator points to a pair, we can access the value using second.
    // If we access map_name["key"] and the key does not exist, it will create a new entry with the default value (0 for int, empty string for string, etc.) and return a reference to it. This can lead to unintended consequences if we are not careful.
    // begin(), end(), rbegin(), rend() iterators can also be used with maps to traverse through the elements.

    map<int, int> freqMap;
    freqMap.insert({1, 5});
    freqMap.insert({2, 3});
    freqMap.insert({3, 8});
    freqMap.insert({4, 1});

    auto l_bound = freqMap.lower_bound(2); // returns an iterator pointing to the first element that is not less than 2
    auto u_bound = freqMap.upper_bound(2); // returns an iterator pointing to the first element that is greater than 2
    cout << "Lower bound for 2: " << l_bound->first << " with frequency " << l_bound->second << endl;
    cout << "Upper bound for 2: " << u_bound->first << " with frequency " << u_bound->second << endl;
    return 0;
}