//longest subarray of sum k;

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long k;
    cout << "Enter the sum value: ";
    cin >> k;

    int left = 0 , right = 0;

    long long sum = arr[0];
    int maxLen = 0;

    while (right<n)
    {
        while (left<=right && sum>k)
        {
            sum-=arr[left];
            left++;
        }
       if(sum == k){
            maxLen = max(maxLen , right-left+1);
       }
       right++;
       if(right<n) sum+=arr[right];
        
    }
    
    

cout << "Maximum subarray length: " << maxLen;




    return 0;
}


//TC worst case O(2n)
// Time Complexity: O(n)
// - The right pointer traverses the array at most n times.
// - The left pointer also moves forward at most n times.
// - Each element is added to and removed from the window at most once.
// - Overall: O(n).
//
// Space Complexity: O(n)
// - The input vector stores n elements.
// - The sliding window uses only a few variables (O(1) auxiliary space).
// - Overall space: O(n), including the input array.
// - Auxiliary space: O(1).