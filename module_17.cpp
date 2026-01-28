#include<bits/stdc++.h>
using namespace std;

// STL pair: The pair is a container in the C++ Standard Template Library (STL) that holds two values, which may be of different types. It is defined in the <utility> header file. The pair is often used to store a simple association between two values, such as a key-value pair in a map.

int main(){
    
    pair<int, string> p; // pair of int and string
    p = make_pair(1, "Hello");      // also can be p = {1, "Hello"} or pair<int, string> p(1, "Hello"); or p.first = 1; p.second = "Hello";
    cout << "First element: " << p.first << endl; // Accessing first element
    cout << "Second element: " << p.second << endl; // Accessing second element

    return 0;
}