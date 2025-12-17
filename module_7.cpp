#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int age;
    int roll;
    float marks;
};

// Comparator function to sort students objects
bool cmp(Student left, Student right)       //left and right are two Student objects that need to be compared & comes from sort function as an argument
{
    return left.marks != right.marks ? left.marks > right.marks : left.roll < right.roll; // if marks are not equal then sort based on marks in descending order else sort based on roll in ascending order, returns true or false. Ascending if left is less than right & descending if left is greater than right.
}

// How this sort function works: Its a hybrid sorting algorithm derived from quicksort, heapsort, and insertion sort. It begins by dividing the array into smaller segments and sorting them using insertion sort for small sizes. For larger segments, it employs quicksort to partition the data efficiently. If the recursion depth exceeds a certain level, it switches to heapsort to ensure O(n log n) performance. This combination allows std::sort to be both fast and reliable across various data distributions.

int main()
{

    int n;
    cin >> n;

    Student arr[n]; // array of objects
    for (int i = 0; i < n; i++)
    {
        cin.ignore();              // to ignore the newline character left in the input buffer
        getline(cin, arr[i].name); // to take string input with spaces
        cin >> arr[i].age >> arr[i].roll >> arr[i].marks;
    }

    // sorting based the array of objects based on marks in descending order. If marks are same then sort based on age in ascending order.
    sort(arr, arr + n, cmp); // cmp is a comparator function defined above

    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ": " << endl;
        cout << "Name: " << arr[i].name << endl;
        cout << "Age: " << arr[i].age << endl;
        cout << "Roll: " << arr[i].roll << endl;
        cout << "Marks: " << arr[i].marks << endl;
        cout << endl;
    }

    return 0;
}