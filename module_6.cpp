#include<bits/stdc++.h>
using namespace std;

int main(){
    // !String Constructor: Various ways to create and initialize strings in C++ using constructors
    string str1; // Default constructor: creates an empty string
    cin >> str1; 
    string str2("Hello, World!"); // Parameterized constructor: initializes with a C-style string
    string str3("Hello, World!", 5); // Parameterized constructor with length: initializes with first 5 characters of C-style string
    string str4(str2); // Copy constructor: initializes with another string. it has an optional second parameter to specify the number of characters to copy.
    string str5(str2, 5); // Copy constructor with length: initializes with first 5 characters of another string
    string str6(5, 'A'); // Fill constructor: creates a string with 5 'A' characters
    
    cout << "str1(default): " << str1 << endl;
    cout << "str2(constructor like): " << str2 << endl;
    cout << "str3(parameterized with length): " << str3 << endl;
    cout << "str4(copy constructor): " << str3 << endl;
    cout << "str5(copy constructor with length): " << str4 << endl;
    cout << "str6(fill constructor): " << str5 << endl;

    // !String sorting
    string str("dcbaefgh");
    sort(str.begin(), str.end());       // begin() and end() return iterators to the start and end of the string respectively
    cout << "Sorted String: " << str << endl;

    // !String Iteration
    for (char c : str1) // range-based for loop to iterate through each character in the string. as same as for(int i=0;i<str.size();i++) 
    {
        cout << c << " "; 
    }
    cout << endl;

    // !String Reverse 
    reverse(str1.begin(), str1.end()); // reverse the string using iterators
    cout << "Reversed String: " << str1 << endl;

    return 0;
}