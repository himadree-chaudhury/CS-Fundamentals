#include <bits/stdc++.h>
using namespace std;
// !Time Complexity O(): 
// Time complexity measures how an algorithm's execution time grows as the input size increases, but it doesn't actually track time beacuse it may vary based on hardware and other factors. It calculates the operations performed relative to input size.
// !Space Complexity S(): 
// Space complexity measures how an algorithm's memory usage grows as the input size increases. It calculates the additional memory required relative to input size, excluding the space taken by the input itself.

// *Aysmptotic Notations: 
// It is a mathematical concept used to describe the behavior of functions as the input size approaches infinity. In computer science, asymptotic notations are commonly used to analyze the time complexity and space complexity of algorithms.
// 1. Big O Notation O(): It represents the upper bound of an algorithm's time complexity. It provides a worst-case scenario for how the algorithm performs as the input size grows. For example, if an algorithm has a time complexity of O(n^2), it means that in the worst case, the execution time will grow quadratically with the input size n.
// 2. Omega Notation Ω(): It represents the lower bound of an algorithm's time complexity. It provides a best-case scenario for how the algorithm performs as the input size grows. For example, if an algorithm has a time complexity of Ω(n), it means that in the best case, the execution time will grow linearly with the input size n.
// 3. Theta Notation Θ(): It represents a tight bound of an algorithm's time complexity. It provides both the upper and lower bounds for how the algorithm performs as the input size grows. For example, if an algorithm has a time complexity of Θ(n log n), it means that the execution time will grow proportionally to n log n in both the best and worst cases.

// *Rules to calculate Time Complexity:
// 1. Always consider the worst-case scenario for time complexity analysis.
// 2. Ignore constant factors and lower-order terms when expressing time complexity using Big O notation.

// *Rules to calculate Space Complexity:
// 1. Other than array, the space complexity of variables is O(1) as they occupy constant space.
// 2. For a loop that runs n times and uses a constant amount of space in each iteration, the space complexity is O(1) as only a single instance of the variable is maintained throughout the loop.
// 3. For a recursive function/1D array that makes n recursive calls/has n elements, the space complexity is O(n) as each call/element occupies space on the call stack/memory.
// 4. For a 2D array that has n x m elements, the space complexity is O(n*m) as each element occupies space in memory.

int main()
// The overall time complexity is determined by identifying the most significant/costly term among all the individual complexities calculated for different parts of the code not by summing them up. 
{
    // % 1.Linear Complexity O(n): The time complexity grows linearly with the input size.
    for (int i = 0; i < 100; i++) // O(n)
    {
        cout << i << " "; // O(1)
    } // Overall O(100) => O(n) when n=100
    cout << endl;

    // %2. Logarithmic Complexity O(log n): The time complexity grows logarithmically(increment/decrement-based) with the input size, commonly seen in divide and conquer algorithms.
    int n = 16;
    for (int i = 1; i < n; i = i * 2) // O(log n)
    {
        cout << i << " "; // O(1)
    } // Overall O(4) => O(log n) when n=16(2-based)
    cout << endl;

    // % 3. Sqare root Complexity O(√n): The time complexity grows proportionally to the square root of the input size.
    n = 100;
    for (int i = 1; i * i <= n; i++) // O(√n)
    {
        cout << i << " "; // O(1)
    } // Overall O(10) => O(√n) when n=100
    cout << endl;

    // % 4. Quadratic Complexity O(n^2): The time complexity grows quadratically with the input size, commonly seen in nested loops.
    n = 5;
    for (int i = 0; i < n; i++) // O(n)
    {
        for (int j = 0; j < n; j++) // O(n)
        {
            cout << "(" << i << "," << j << ") "; // O(1)
        }
    } // Overall O(25) => O(n*n) => O(n^2) when n=5
    // If both loops are independent then O(n*m) where n and m are different inputs. As same for more than 2 loops, Overall O(n^k) where k is the number of loops or O(n*p*q...) where p,q are different inputs.
    cout << endl;

    // % 5. Linearithmic Complexity O(n log n): The time complexity grows proportionally to n log n.
    n = 8;
    for (int i = 0; i < n; i++) // O(n)
    {
        for (int j = 1; j < n; j = j * 2) // O(log n)
        {
            cout << "(" << i << "," << j << ") "; // O(1)
        }
    } // Overall O(24) => O(8*3) => O(n log n) when n=8
    cout << endl;

    // Best to Worst Case Complexity: Let N=1000
    // 1. Constant O(1): 1
    // 2. Logarithmic O(log n): ~10
    // 3. Square Root O(√n): ~32
    // 4. Linear O(n): 1000
    // 5. Linearithmic O(n log n): ~10,000
    // 6. Quadratic O(n^2): 1,000,000

    // Normally the onlne judges can run 10^7 ~ 10^8 operations per second and have a time limit of 1 or 2 seconds. If the number of operations exceeds this limit, a TLE (Time Limit Exceeded) error may occur.
    return 0;
}