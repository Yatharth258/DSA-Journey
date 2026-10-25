//search for minimum in rotated sorted array

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


    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

         if(arr[low] == arr[mid] && arr[mid] == arr[high]){ // just this block added extra rest all the code are same 
             ans = min(ans,arr[low]);
            low++;
            high--;
            continue;
        }

        if(arr[mid]>=arr[low]){ //left half is sorted 
           ans = min(ans,arr[low]);
           high = mid-1;
        }else{ //right half is sorted
           ans = min(ans,arr[mid]);
           low = mid+1;
        }
    }

    cout<<"The smallest element in given array is : "<<ans;

    return 0;
}

/*
    Time Complexity:
    Best/Average Case: O(log n)
    Worst Case: O(n)   // due to duplicates

    Space Complexity: O(1)
*/