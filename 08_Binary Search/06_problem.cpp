//finding the single elemnt in an sorted array 
//in an given array all the nuber will be appearing twice and only one element will appear once , you need to find out that number

//Brute force -->  arr[i]==arr[i-1] || arr[i]==arr[i+1] ; handle edge cases seperately 

//Method 2: since array is sorted --> Binary Search
//Little bit of theroy or observation --> since array is sorted therefore all the repeated elemnts are present in pairs
//we observed that :
//for elemnt in left of single elemnt , pair elemnt follow this index pattern (even,odd) {that means we need to eliminate left half since elmnt is on right half}
//for elemnt in right of single elemnt , pair elemnt follow this index pattern (odd,even) {that means we need to eliminate right half since elmnt is on left half}

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
        cout << "Single element is: " << arr[0];
        return 0;
    }

    // Check first element
    if(arr[0] != arr[1])
    {
        cout << "Single element is: " << arr[0];
        return 0;
    }

    // Check last element
    if(arr[n - 1] != arr[n - 2])
    {
        cout << "Single element is: " << arr[n - 1];
        return 0;
    }

    int low = 1;
    int high = n - 2;
    int ans = -1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        // Single element found
        if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        {
            ans = arr[mid];
            break;
        }

        // We are in the left half so elimimnating left half
        if((mid % 2 == 1 && arr[mid] == arr[mid - 1]) ||
           (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
        {
            low = mid + 1;
        }
        else
        {
            // We are in the right half so eliminationg right half
            high = mid - 1;
        }
    }

    cout << "Single element is: " << ans;

    return 0;
}

/*
    Time Complexity: O(log n)
    Space Complexity: O(1)
*/