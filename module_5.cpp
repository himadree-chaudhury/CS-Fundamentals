#include <bits/stdc++.h>
using namespace std;

//* Capacity
// s.size() -> returns the size of the string.
// s.max_size() -> returns the maximum size that string can hold. It varies from system to system.
// s.capacity() -> returns current available capacity of the string. The capacity will automatically increase if the size exceeds the current capacity.
// s.clear() -> clear the string.
// s.empty() -> return true/false if the string is empty. Behind the scenes it checks if size is 0 or not.
// s.resize() -> change the size of the string. If the new size is greater than the current size, the string is expanded and new characters are filled with null characters ('\0') or a specified character. If the new size is smaller, the string is truncated to the new size.
//* Element access
// S[i] -> access the ith index of the string.
// s.at(i) -> access the ith index of the string. Same as S[i] but with bounds checking. It throws an out_of_range exception if the index is invalid.
// s.back() -> access the last element of the string.
// s.front() -> access the first element of the string.
//* Modifiers
// s+= -> append or concatenate another string.
// s.append() -> append another string.
// s.push_back() -> add character to the last of the string. Only a single character can be added.
// s.pop_back() -> remove the last character of the string.
// s= -> assign string. Character array can not be assigned directly using = operator, it requires strcpy() function from <cstring> header.
// s.assign() -> assign string.
// s.erase() -> erase characters from the string. It can erase a portion of the string from a specific index for a given length.
// s.replace() -> replace a portion of the string. It can replace a portion of the string from a specific index for a given length with another string.
// s.insert() -> insert a portion to a specific position.
//* Iterators
// s.begin() -> pointer to the first element.
// s.end() -> pointer to the next element after the last element of the string.
// s.rbegin() -> pointer to the last element.
// s.rend() -> pointer to the element before the first element of the string.

int main()
{
    string str;
    getline(cin, str); // to take string input with spaces. If there is a enter at the beginning of input buffer then it will be considered as input. To avoid that we can use cin.ignore() before getline() to ignore the newline character in the input buffer. If there is no space in the input then cin>>str; also works.
    // getline() is different for char arrays and strings. For char arrays we use: cin.getline(char_array, size) but for strings we use: getline(cin, string_variable)

    cout << "String Size: " << str.size() << endl;
    cout << "Max Size: " << str.max_size() << endl;
    cout << "Capacity: " << str.capacity() << endl;
    cout << "Is Empty: " << str.empty() << endl;
    str.resize(15, '*'); // resize to 15, fill new positions with '*' instead of null characters or garbage values
    cout << "Resized String: " << str << endl;
    str.resize(13); // resize back to 13, truncate extra characters
    cout << "Resized String: " << str << endl;
    str.clear();
    cout << "Is Empty after clear: " << str.empty() << endl; // 1 for true

    str = "Himadree";
    cout << "Assigned new value: " << str << endl;
    cout << "First & Last Character: " << str.front() << " " << str.back() << endl;

    string str2 = "Chaudhury";
    str += " " + str2; // append str2 to str. str.append(" " + str2); also works
    cout << "Appended String: " << str << endl;
    str.push_back('!');
    cout << "String after push_back: " << str << endl;
    str.pop_back();
    cout << "String after pop_back: " << str << endl;

    str.assign("Hello, World!"); // replace the entire string with new value
    cout << "Assigned String using assign(): " << str << endl;
    str.erase(5, 7); // erase 7 characters from index 5
    cout << "String after erase(): " << str << endl;
    str.replace(5, 0, ", C++17!"); // replace 0 characters at index 5 with ", C++17!"
    cout << "String after replace(): " << str << endl;
    str.insert(5, " Amazing"); // insert " Amazing" at index 5
    cout << "String after insert(): " << str << endl;

    cout << "Characters using iterators: ";
    for (string::iterator it = str.begin(); it < str.end(); it++) // string::iterator can also be written as auto from C++11 onwards
    {
        cout << *it << " "; // dereference the iterator to get the character
    }
    cout << endl;

    // stringstream for splitting string: used to split string words by spaces
    string sentence = "C++ is a powerful programming language";
    stringstream ss(sentence); // create stringstream object with the sentence
    string word;
    ss >> word; // extract first word from the stringstream, ss gives word and deletes it from the stream
    cout << "Word 1: " << word << endl;
    cout << "Splitted words: ";
    while (ss >> word) // extract words until the stream is empty
    {
        cout << word << " " << endl;
    }
    cout << endl;

    return 0;
}