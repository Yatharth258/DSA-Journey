//find the smallest index which is arr[i]>=x(target) {in upper bound arr[i]>x}
//in case you dont found the lower bound we are returning the size of array (n)


//ANOTHER Problem with same solution
// Problem Statement:
// You are given a sorted array 'arr' of distinct values and a target value 'm'. You
// need to search for the index of the target value in the array.
// If the value is present in the array, then return its index.
// If the value is not present, determine the index where it would be inserted in the
// array while maintaining the sorted order.
// Example:
// arr = [1, 2, 4, 7] , m=6
// Output: 3
// Explanation: If the given array 'arr' is: [l, 2, 4, 7] and m
// = 6. We insert m = 6 in the array and get 'arr' as: [l, 2,
// 4, 6, 7]. The position ot 6 is 3 (according to 0-based indexing



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
    int ans = n;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid] >= target) //UPPER BOUND: in case of upper bound only differnce is = sign rest all the code is same i.e "if(arr[mid] > target)"
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout<<"The lower bound of given target is : "<<ans;

    return 0;
}

//TC O(logn) {log base 2}
//SC O(1)


/*
    lower_bound() → returns iterator to first element >= target.
    
    Syntax:
    lower_bound(arr.begin(), arr.end(), target); -->NOTE: it returns the iterator pointing to the lower bound number not actually that index 

    For range [l, r]:
    lower_bound(arr.begin() + l, arr.begin() + r + 1, target);

    Get index:
    int index = it - arr.begin(); --> we are subtracting two pointer , hence got an integer number which is required index

    Array must be sorted.
    Time Complexity: O(log n)
*/