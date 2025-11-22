#include<iostream>      // Input Output Stream Library
#include<iomanip>       // Input Output Manipulation Library (for setprecision, etc.)
#include<algorithm>     // Algorithm Library (for min, max, swap, etc.)

//! #include<bits/stdc++.h>  // This header file includes every standard library.

int main(){
    std::cout << "Hello, World!"<< "\n";   // std is the standard namespace, cout is the character output stream

    // In c++, there is no format specifier like in C (e.g., %d, %c, %f, etc.)
    int a;
    double b;
    char c;
    char s[100]; 
    char t[100]; 

    std::cin >> a >> b >> c >> s;   // std is the standard namespace, cin is the character input stream. For each input use >> operator.

    // If the string has spaces, then cin will take input only until the first space. To take input with spaces, we can use std::getline(variable, size) function. We can use fgets() from C library as well.
    // std::cin.getline(s, 100);  // To take string input with spaces
    // std::cin.ignore();  // To ignore the newline character left in the input buffer

    std::cin.ignore();  // To ignore the newline character left in the input buffer after reading character input
    std::cin.getline(t, 100);  // To take string input with spaces

    std::cout << "Integer:" << a << " "<< "Double:" << b << " " << "Character:" << c << " " << "String:" << s << " " << "String with spaces:" << t << std::endl;  // endl is used to insert a new line and flush the stream like \n. For each output use << operator.

    // *Writing std every time is tedious, we can use 'using namespace std;' after including libraries to avoid writing std every time.

    // In C we can get the ascii value of a character by simply assigning it to an integer variable.
    // In C++, we need to use static_cast<type>(variable) to convert a variable from one type to another type or we can use C-style casting (type)variable.

    int ascii_c = c;  // Implicit type conversion from char to int
    int ascii_c_explicit = static_cast<int>(c);  // Explicit type conversion using static_cast, as same integer can be converted to char using static_cast<char>(variable)

    std::cout << "ASCII value of " << c << " is: " << ascii_c<<"(Implicit)" << " " << ascii_c_explicit<<"(Explicit)" << std::endl;

    // EOF: End Of File
    int x;
    while(std::cin >> x){   // Take input until End Of File
        std::cout << x << std::endl;
    }   

    // Setprecision can be used to set the precision of floating point numbers. Need to include <iomanip> library.
    double num = 2.123456789;
    std::cout << std::setprecision(5) << num << std::endl;  // By default, setprecision sets the total number of significant digits. To set the number of digits after the decimal point, use std::fixed manipulator.
    std::cout << std::fixed << std::setprecision(5) << num << std::endl;


    // Min, Max, Swap, Need to include <algorithm> library.
    int p = 10, q = 20;
    std::cout << "Min: " << std::min(p, q) << std::endl;        // min calculate the minimum of some values, if there are more than two values, use { , } to enclose the values. e.g., std::min({a, b, c, d, e})

    std::cout << "Max: " << std::max(p, q) << std::endl;        // max calculate the maximum of some values, if there are more than two values, use { , } to enclose the values. e.g., std::max({a, b, c, d, e})
    
    std::swap(p, q);                     // swap the values of two variables
    std::cout << "After swap, p: " << p << " q: " << q << std::endl;

    return 0;
}