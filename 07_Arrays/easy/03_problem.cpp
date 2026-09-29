//check if the array is sorted


#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cout<<"Enter the length of the array :";
    cin>>n;
    vector<int> arr(n);

    cout<<"Enter the elemts of the array : ";
    for (int i = 0; i < n; i++)
    {
       cin>>arr[i];
    }

    bool isSorted = true;
    for (int i = 0; i < n-1; i++)
    {
       if(arr[i]>arr[i+1]){
        isSorted = false;
        break;
       }
    }
    
    if(isSorted){
        cout<<"The given array is sorted";
    }else{
        cout<<"The given array is not sorted";
    }


    return 0;
}


// Time Complexity: O(n) in the worst case, because you may need to check every adjacent pair.

// Best Case: O(1), if the first pair is out of order.

// Space Complexity: O(1) for the checking logic, excluding the input array.