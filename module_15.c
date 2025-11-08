#include <stdio.h>

void pointerFunction(int *p)
{
    // Function that takes a pointer as an argument
    *p = 30; // Modify the value at the address pointed to by p
}

void arrayFunction(int a[], int size)
{

    // int a[] can also be written as int *a because when we pass an array to a function, it decays to a pointer to the first element. For string we don,t need to pass size as we cen get the size by checking for null character or strlen().

    printf("Address of array in function: %p\n", a);
    // See that the address of the array passed to the function is same as the address of the array in main function.

    a[0] = 100; // Modify the first element of the array

    // We can not return an array from a function directly because returning cause a cleanup issue that clears the stack of this function except the first element as it returns the array name which is a pointer to the first element. However, we can return a pointer to the first element of the array or use dynamic memory allocation to create an array within the function and return its pointer.
}

int main()
{
    // *Pointer: Pointer is a variable that stores the memory address of another variable.

    // In typical variables, the variable name directly refers to the value stored in that memory location.
    int x = 10;
    printf("Address of x: %p\n", &x); // Print the memory address of x

    // But in pointers, the variable name refers to the memory address of another variable. Pointer can be used to access and modify the value of the variable it points to. Remember that pointer itself is also a variable and has its own memory address.

    // syntax: data_type *pointer_name;

    int *ptr = &x; // Pointer variable that holds the address of x

    printf("Value of pointer: %p\n", ptr);

    printf("Value of x: %d\n", *ptr); // Dereference pointer to get the value of x
    // Dereferencing a pointer means accessing the value stored at the memory address the pointer is pointing to.

    // Reference vs Dereference
    // Reference: Getting the address of a variable using the & operator. That means value -> address. e.g. scanf("%d", &x);
    // Dereference: Accessing the value at the address stored in a pointer using the * operator. That means address -> value.

    printf("Address of pointer variable ptr: %p\n", &ptr); // Address of the pointer variable itself

    *ptr = 20; // Modify the value of x using the pointer
    printf("New value of x: %d\n", x);

    // %Pointer importance in function arguments:
    // 1. Pass by value: When a variable is passed to a function as a parameter, a copy of the variable is made. Changes made to the parameter inside the function do not affect the original variable. The value that function received and the original value are passed both stored in different memory locations, so their scope is different, means functional scope can't access the original variable.e.g printf()

    // 2. Pass by reference: When a pointer to a variable is passed to a function, the function can modify the original variable's value by dereferencing the pointer. That means both the original variable and the parameter point to the same memory location, so their scope is same, means functional scope can access the original variable.e.g scanf()

    pointerFunction(&x); // Pass the address of x to the function
    printf("Value of x after pass by reference: %d\n", x);

    // In a nutshell, pointers make the function able to modify the original variable's value by passing its address, enabling the variable to be changed outside the function's scope.e.g. We use & in scanf(), so we basically pass the address of the variable to store the input value directly in that memory location.By doing this, we can modify the original variable's value from within the function.

    // When we use scanf, it needs to put the input (like integer 5) into our variable. But if we just pass the variable’s value, scanf only gets a copy - it can’t change the real one in main because of functional scope. By using the & operator, we give scanf the variable’s address in memory. That way, scanf can go straight to that spot and store the input there. So the original variable in main actually changes. Because main holds the real variable, and scanf uses the address to update it directly.

    // Pointer in arrays:
    int arr[5] = {1, 2, 3, 4, 5};
    //   The name of the array (arr) acts as a pointer to the first element of the array. That means arr is equivalent to &arr[0]. So the array name is stored in the memory location of the first element of the array.

    printf("Address of the array arr: %p\n", arr);

    for (int i = 0; i < 5; i++)
    {
        printf("Address at arr[%d] = %p\t", i, &arr[i]);
        printf("Value of arr[%d] = %d\n", i, arr[i]);
    }

    // In both cases, the address of the first element of the array is the same as the address of the array itself. So we can use do all the pointer operations on arrays as well.

    printf("Value of the first element using dereferencing: %d\n", *arr); // Dereferencing the array name to get the value of the first element

    *arr = 10;       // Modifying the first element using pointer dereferencing
    *(arr + 1) = 20; // Modifying the second element using pointer arithmetic
    printf("New value of the first element: %d\n", arr[0]);
    printf("New value of the second element: %d\n", arr[1]);

    // Passing array to function using pointer
    arrayFunction(arr, 5); // Pass the array and its size to the function

    printf("Value of the first element after function call: %d\n", arr[0]);

    // An interesting fact about arrays and pointers is that when we pass an array to a function, what actually gets passed is a pointer to the first element of the array. This means that any modifications made to the array elements within the function will directly affect the original array in the calling function. This way we prevent copying the entire array, which can be inefficient for large arrays.


    // When we input an string using scanf, it works even without & operator because the name of the string array acts as a pointer to the first element of the array. So when we pass the string array to scanf, it receives the address of the first character of the string, allowing it to store the input directly in that memory location.
    return 0;
}
