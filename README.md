# Basic Data Structures

This directory contains resources and materials related to basic data structures, including arrays, linked lists, stacks, queues, and more. It is designed to help learners understand the fundamental concepts and implementations of these data structures in programming.

## Vector Built-in Functions:

### 1. Initialization

| Name                     | Details                                                       | Time Complexity |
|--------------------------|---------------------------------------------------------------|-----------------|
| vector<type> v;          | Construct a vector with 0 elements                            | O(1)            |
| vector<type> v(N);       | Construct a vector with N elements                            | O(N)            |
| vector<type> v(N, V);    | Construct a vector with N elements, each initialized to V     | O(N)            |
| vector<type> v(v2);      | Copy constructor, copies all elements from v2                 | O(N)            |
| vector<type> v(A, A+N);  | Construct vector from array A of size N                       | O(N)            |


### 2. Capacity
	
| Name        | Details                                                         | Time Complexity |
|-------------|------------------------------------------------------------------|-----------------|
| v.size()    | Returns the number of elements                                  | O(1)            |
| v.max_size()| Returns maximum number of elements vector can hold              | O(1)            |
| v.capacity()| Returns current allocated capacity                              | O(1)            |
| v.clear()   | Removes all elements (memory not freed)                         | O(N)            |
| v.empty()   | Checks whether the vector is empty                              | O(1)            |
| v.resize()  | Changes the size of the vector                                  | O(K)            |

K = difference between new size and current size


### 3. Modifiers

| Name           | Details                                                         | Time Complexity              |
|----------------|------------------------------------------------------------------|------------------------------|
| v = v2         | Assign another vector                                           | O(N) or O(1)                 |
| v.assign()     | Assign new values to the vector                                 | O(N)                         |
| v.push_back()  | Adds an element to the end                                      | O(1) amortized               |
| v.pop_back()   | Removes the last element                                        | O(1)                         |
| v.insert()     | Inserts elements at a given position                            | O(N + K)                     |
| v.erase()      | Removes elements from a given position                          | O(N + K)                     |


### 4. Element access

| Name        | Details                      | Time Complexity |
|-------------|------------------------------|-----------------|
| v[i]        | Access ith element           | O(1)            |
| v.at(i)     | Access ith element (checked) | O(1)            |
| v.front()   | Access first element         | O(1)            |
| v.back()    | Access last element          | O(1)            |



### 5. Iterators

| Name      | Details                          | Time Complexity |
|-----------|----------------------------------|-----------------|
| v.begin() | Iterator to first element        | O(1)            |
| v.end()   | Iterator to one past last element| O(1)            |


### 6. Algorithms (Not Vector Member Functions)

| Name                                                  | Details                                   | Time Complexity |
|-------------------------------------------------------|-------------------------------------------|-----------------|
| replace(v.begin(), v.end(), val, new_val)             | Replace all occurrences of val            | O(N)            |
| find(v.begin(), v.end(), V)                           | Find value V                              | O(N)            |


