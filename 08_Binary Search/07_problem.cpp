//Find the peak element  {arr[i-1]<arr[i]>arr[i+1]}
//certain coditions --> in case of increasing or decreasing array return the highest elemnt index i,e 0th index or n-1 index
//Note : condition on input --> consecutive numbers should never be equal
//in case of multiple peak you are allowed to return any one of the peak

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if(n == 1)
    {
        cout << "Peak element is at index: 0";
        return 0;
    }

    // Check first element
    if(arr[0] > arr[1])
    {
        cout << "Peak element is at index: 0";
        return 0;
    }

    // Check last element
    if(arr[n - 1] > arr[n - 2])
    {
        cout << "Peak element is at index: " << n - 1;
        return 0;
    }

    int low = 1;
    int high = n - 2;
    int ans = -1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        // Peak found
        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            ans = mid;
            break;
        }

        // Increasing slope → peak is on right
        if(arr[mid] > arr[mid - 1])
        {
            low = mid + 1;
        }
        else
        {
            // Decreasing slope → peak is on left
            high = mid - 1;
        }
    }

    cout << "Peak element is at index: " << ans;

    return 0;
}

/*
    Time Complexity: O(log n)
    Space Complexity: O(1)

    NOTE:
    This also handles multiple peaks.

    Example:
    [1, 5, 1, 2, 1]

    If we are on an increasing slope:
        arr[mid] > arr[mid - 1]
    → Move right.

    Otherwise:
        → Move left.

    We don't need to find the first peak.
    Any peak is a valid answer.

    This avoids the infinite-loop issue that can occur
    if we don't properly eliminate one half.
*/