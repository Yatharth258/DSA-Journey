
/*
Question:
Given a sorted array of positive integers, find the k-th
positive integer that is missing from the array.

Example:
arr = {2, 3, 4, 7, 11}
k = 5

Missing numbers = {1, 5, 6, 8, 9, 10, ...}

5th missing number = 9
*/

#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, k;

    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> vec(n);

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    cout << "Enter k: ";
    cin >> k;

    int low = 0;
    int high = n - 1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        // Number of missing elements before vec[mid]
        int missing = vec[mid] - (mid + 1);

        if(missing < k)
        {
            // We need more missing numbers,
            // so move towards the right
            low = mid + 1;
        }
        else
        {
            // We already have k or more missing numbers,
            // so try the left side
            high = mid - 1;
        }
    }

    // Answer = k + number of elements before the answer
    cout << "K-th missing number: " << k + high + 1;

    /*
    Time Complexity:
    Binary Search = O(log n)

    TC = O(log n)

    Space Complexity:
    No extra space apart from the input array.

    SC = O(1) auxiliary space
    */

    return 0;
}