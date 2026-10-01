//find the maximum subarray sum
//you will be given an array with postive an dnegative array , we need to find out the maximum subarray

// Brute force approach -->TC O(n^2)

//Kedane's Algorithm

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

    int sum = 0;
    int maxi = INT_MIN;

    int start = 0, ansStart = -1, ansEnd = -1;

    for (int i = 0; i < n; i++) {
        if (sum == 0) {
            start = i;
        }

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0) {
            sum = 0;
        }
    }

    cout << "Maximum subarray sum is: " << maxi << endl;

    cout << "Maximum subarray is: ";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
Time Complexity: O(n)
- Single traversal of the array: O(n).
- Printing the subarray: O(n) in the worst case.
- Overall: O(n).

Space Complexity: O(1)
- Only a few extra variables are used.
- No additional data structure is required.
*/


