#include <bits/stdc++.h>
using namespace std;

// class: user-defined data type. An empty class has size of 1 byte to ensure that two different objects of the class have different addresses in memory. 
// object: instance/variable of a class

class Student
{
    // attributes
public: // access specifier: public, private, protected
    string name;
    int age;
    float marks;

    // constructor: help to initialize the attributes, without it the object have to create by variable_name.attribute_name but constructor help to initialize at the time of object creation. Constructor name must be same as class name and it has no return type.
    Student(string name, int age, float marks)
    {
        this->name = name;
        this->age = age;
        this->marks = marks;

        // this pointer: point to the current object. Here this->name means current object's name attribute & it can also be represented as (*this).name. It means the name is get by dereferencing the current object pointer and accessing its name attribute then store the value passed in the constructor to it.
    }

    // methods
    void printDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Marks: " << marks << endl;
    }
};

// An object can be returned from a function, and the return type must match the object’s type. A local object inside the function is destroyed when the function ends, but that doesn’t make the returned value invalid. When returning an object by value, the compiler creates a separate return object, so the caller still receives a valid one. An object only needs to be created dynamically when its lifetime must continue beyond normal scope rules and be managed manually.

Student createStudent(string name, int age, float marks)
{
    Student s(name, age, marks); // local object creation inside the function, this object will be destroyed when the function ends
    return s;                    // return by value, a copy of the object is made and returned
}

Student *createStudentDynamic(string name, int age, float marks)
{
    // Student s(name, age, marks); // local object creation inside the function
    // Student *ptr = &s;          // returning address of local object (bad practice)
    // return ptr;               // returning address of local object which will be destroyed when the function ends, leading to dangling pointer

    // If the object is created statically by Student s("Jessica", 22, 92.0) then it will be destroyed when the function ends.So, we can not access when the function ends as the pointer address will be invalid. But if we create the object dynamically using new keyword then it will not be destroyed when the function ends and we can access it later.But we have to delete it manually to avoid memory leak.

    Student *s = new Student(name, age, marks); // dynamic object creation inside the function.
    return s;                                   // return by pointer
}

int main()
{
    // object creation by using constructor
    Student s1("Alice", 20, 85.5);
    s1.printDetails();

    // object creation by using variable_name.attribute_name (works only if there is no constructor defined)
    // Student s2;
    // s2.name = "Bob";
    // s2.age = 22;
    // s2.marks = 90.0;

    // Creating object by function return
    Student s3 = createStudent("Charlie", 21, 88.0);
    s3.printDetails();

    // Creating dynamic object by function return
    Student *s4 = createStudentDynamic("David", 22, 91.0);
    cout << (*s4).name << endl<< (*s4).age << endl << (*s4).marks << endl; // access the attribute using pointer dereferencing, this also can be done s4->name, s4->age, s4->marks
    s4->printDetails(); // access the method using pointer
    delete s4; // free the dynamically allocated memory


    // Built-in sort function
    // sort(start_iterator, end_iterator + 1, comparator_function);
    int ary[] = {5, 2, 8, 1, 3};
    int n = sizeof(ary) / sizeof(ary[0]);       // Why sizeof(ary) / sizeof(ary[0])? because sizeof(ary) gives the total size of the array in bytes and sizeof(ary[0]) gives the size of one element in bytes. Dividing these two gives the number of elements in the array.
    sort(ary, ary + n); // sort in ascending order, Why arr & arr + n? because arr gives the starting address of the array as array name indicates the first index and arr + n is the address just after the last element of the array.

    for (int i = 0; i < n; i++)
    {
        cout << ary[i] << " ";
    }
    cout << endl;

    sort(ary, ary + n, greater<int>()); // sort in descending order, greater<int>() is a built-in comparator function. It's int because the array is of int type. If the array is of float type then it will be greater<float>() and so on.
    for (int i = 0; i < n; i++)
    {
        cout << ary[i] << " ";
    }
    cout << endl;

    return 0;
}