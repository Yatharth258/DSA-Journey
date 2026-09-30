//longest subarray with sum k
// that is , in an array we need to find the contiguous subarray with largest length whose sum is coming up as k

//method 1 --> brute force method --> calculate all sub array and check wether its sum is euqal to k and in last store max length in some varaible and print it out 
//--> tc(n^3) and sc(1)


//method 2 --> using hash maps

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

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        long long rem = sum - k;

        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    cout << "Maximum subarray length: " << maxLen;

    return 0;
}


// Time Complexity: O(n log n)
// - Traversing the array takes O(n).
// - Map find operation takes O(log n).
// - Map insertion takes O(log n).
// - These map operations are performed for each array element.
// - Overall: O(n log n).
//
// Space Complexity: O(n)
// - The prefix sum map can store up to n distinct prefix sums.
// - Each entry stores a prefix sum and its corresponding index.
// - Overall auxiliary space: O(n).