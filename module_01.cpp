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
    return 0;
}