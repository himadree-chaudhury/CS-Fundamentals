#include <bits/stdc++.h>
using namespace std;

// *Vector: Vector is a dynamic array that can grow and shrink in size as needed. It is part of the C++ Standard Template Library (STL) and provides various built-in functions to manipulate the array easily without worrying about memory management.

// %1. Initialization:
// i.vector<type> v: Construct a vector with 0 elements. O(1)
// ii.vector<type> v(N): Construct a vector with N elements. O(N)
// iii.vector<type> v(N, V): Construct a vector with N elements and the value will be V. O(N)
// iv.vector<type> v(v2): Construct a vector by copying another vector v2. O(N)
// v.vector<type> v(A, A + N):Construct a vector by copying all elements from an array A of size N. O(N)
// vi.vector<type> v = {a1, a2, a3,...}: Construct a vector with initial values a1, a2, a3,...O(N)

// %2. Capacity:
// i.v.size(): Returns the size of the vector. O(1)
// ii.v.max_size(): Returns the maximum size that the vector can hold. O(1)
// iii.v.capacity(): Returns the current available capacity of the vector. Vector doubles its capacity when the current capacity is full e.g., 1->2->4->8...O(1)
// iv.v.clear(): Clears the vector elements.Do not delete the memory,only clear the size. O(N)
// v.v.empty(): Return true / false if the vector is empty or not. O(1)
// vi.v.resize(): Change the size of the vector. O(K) where K = difference between new size and current size

// %3. Modifiers:
// i.v = or v.assign(): Assign another vector. O(N) if sizes are different, O(1) otherwise.
// ii.v.push_back(): Add an element to the end. O(1)
// iii.v.pop_back(): Remove the last element. O(1)
// iv.v.insert(position, new_value): Insert elements at a specific position. O(N+ K) where K is the number of elements inserted.
// v.v.erase(start_position, end_position): Delete elements from a specific position. O(N + K) where K is the number of elements deleted.
// vi.replace(v.begin(), v.end(), value, replace_value): Replace all the value with replace_value.Not under a vector. O(N)
// vii.find(v.begin(), v.end(), V): Find the value V.Not under a vector. It gives the iterator of the first occurrence of V.vector<int>:: iterator it = find(v.begin(), v.end(), V); O(N)

// %4. Element access:
// i.v[i]: Access the ith element. O(1)
// ii.v.at(i): Access the ith element. O(1)
// iii.v.back(): Access the last element. Same as v[v.size()-1]. O(1)
// iv.v.front(): Access the first element. Same as v[0]. O(1)

// %5. Iterators:
// v.begin(): Pointer to the first element. O(1)
// v.end(): Pointer to the last element. O(1)

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // if the vector size is unknown
    vector<int> v2;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v2.push_back(x);
    }

    for(int x: v) // Range-based for loop (C++11 and above)
    {
        cout << x << " ";
    }
    cout << endl;

    // string vector
    vector<string> vs;
    vs.push_back("Hello");
    vs.push_back("World");
    for (string s : vs)
    {
        cout << s << " ";
    }
    return 0;
}