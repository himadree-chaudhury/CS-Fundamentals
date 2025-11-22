// Dynamic Memory Allocation & Operating in C++
//* Stack Memory: Static memory/compile time memory, limited size, automatically managed like deleted when out of scope
//* Heap Memory: Dynamic memory/runtime memory, larger size, manually managed/user instructed like need to delete or clean-up when not needed anymore

#include <bits/stdc++.h>
using namespace std;

// normally an array returns a pointer to its first element
int *arr_func(int arr_size)
{
    int *arr = new int[arr_size]; // dynamically allocate an array of size arr_size

    // Assigning values to the array
    for (int i = 0; i < arr_size; i++)
    {
        cin >> arr[i];
    }
    return arr;
}

int main()
{
    // Dynamic Memory Allocation in C++
    // new keyword is used to allocate memory on the heap
    int *p = new int; // dynamically allocate an integer
    *p = 42;          // assign value to the allocated memory
    cout << "Value at dynamically allocated memory: " << *p << endl;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int *arr = arr_func(n); // function call to get dynamically allocated array

    // Displaying the array values
    cout << "Dynamically allocated array values: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; // The whole array is accessible even after the arr_func ends, otherwise it could segmentation fault(means trying to access memory not allocated to the program)
    }
    cout << endl;

    // Deallocating memory using delete keyword
    delete p;     // free the single integer memory
    delete[] arr; // free the array memory

    return 0;
}
