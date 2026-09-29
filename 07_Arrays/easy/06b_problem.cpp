//using reverse function


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;

    if (n <= 0) return 0;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int d;
    cout << "Enter value d: ";
    cin >> d;

    d = d % n;  // Handle d greater than n

    // Step 1: Reverse the first d elements
    reverse(arr.begin(), arr.begin() + d);

    // Step 2: Reverse the remaining n-d elements
    reverse(arr.begin() + d, arr.end());

    // Step 3: Reverse the entire array
    reverse(arr.begin(), arr.end());

    cout << "New array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}


//TC ==> O(n)
// SC ==> O(1)