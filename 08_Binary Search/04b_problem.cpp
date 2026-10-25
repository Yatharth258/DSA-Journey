//search in rotated sorted array but this time array may have duplicate elements
// in this case if we find any of the index of target if reapeted then we return that one 

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements in rotated sorted order: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target: ";
    cin >> target;

    int low = 0;
    int high = n - 1;
    int index=-1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid]==target){
             index = mid;
             break;
        }

        if(arr[low] == arr[mid] && arr[mid] == arr[high]){ // just this block added extra rest all the code are same 
            low++;
            high--;
            continue;
        }

        if(arr[mid]>=arr[low]){ //left half is sorted 
            if(arr[low]<=target && target<=arr[mid]) high=mid-1;
            else low=mid+1;
        }else{ //right half is sorted
            if(arr[mid]<=target && target<=arr[high]) low=mid+1;
            else high=mid-1;
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
    Best Case: O(1)
    Average Case: O(log n)
    Worst Case: O(n) {tp be specific O(n/2)}
    becuase:
    When many duplicates exist, we may only eliminate one element from each side per iteration.

    Space Complexity: O(1)
*/