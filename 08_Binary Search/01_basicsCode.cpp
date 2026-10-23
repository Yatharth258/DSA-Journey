//Basic understanding of binary search algorithm

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements in sorted order: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target: ";
    cin >> target;

    int low = 0;
    int high = n - 1;
    int index = -1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid] == target)
        {
            index = mid;
            break;
        }
        else if(arr[mid] < target)
        {
            // Target is on the right side
            low = mid + 1;
        }
        else
        {
            // Target is on the left side
            high = mid - 1;
        }
    }

    if(index != -1)
    {
        cout << "Element found at index: " << index << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }

    return 0;
}

/*
    Time Complexity:
    O(log n)

    In every iteration, we eliminate half of the search space.

    Space Complexity:
    O(1)

    We only use a few variables (low, high, mid, index).
*/



//RECURSIVE AAPROACH

// Recursive Binary Search
int binarySearch(vector<int>& arr, int low, int high, int target)
{
    // Base case: element not found
    if(low > high)
        return -1;

    int mid = low + (high - low) / 2;

    // Target found
    if(arr[mid] == target)
        return mid;

    // Target is in the right half
    if(arr[mid] < target)
        return binarySearch(arr, mid + 1, high, target);

    // Target is in the left half
    return binarySearch(arr, low, mid - 1, target);
}

/*
    Time Complexity: O(log n)
    Space Complexity: O(log n)
    
    Space is O(log n) because of recursive function calls
    stored in the call stack.
*/