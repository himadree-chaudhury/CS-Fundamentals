#include <bits/stdc++.h>
using namespace std;

int main()
{
    // *Prefix sum: Prefix sum is an array that stores the cumulative sum of elements from the beginning of the array up to each index. It allows for efficient range sum queries by precomputing the sums.
    // Prefix Sum Array: An array where each element at index i represents the sum of all elements from the start of the original array up to index i.
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();

    vector<int> prefixSum(n);
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    for (auto x : prefixSum)
    {
        cout << x << " "; // Output: 1 3 6 10 15
    }
    cout << endl;

    // *Binary Search: Binary search is an efficient algorithm for finding a target value within a sorted array. It works by repeatedly dividing the search interval in half, eliminating half of the elements from consideration until the target value is found or the interval is empty. Complexity O(log n)

    int N, testCases;
    cin >> N >> testCases;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end()); // Binary search requires a sorted array. Complexity O(n log n)

    for (int i = 0; i < testCases; i++) // Complexity O(n). Total Complexity O(n * log n) = O(n log n)
    {
        int left = 0, right = N - 1, mid;
        bool found = false;
        int target;
        cin >> target;
        while (left <= right) // Complexity O(log n)
        {

            mid = (left + right) / 2;
            if (v[mid] == target)
            {
                found = true;
                break;
            }
            else if (v[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        if (found)
            cout << "Found" << endl;
        else
            cout << "Not Found" << endl;
    }

    return 0;
}